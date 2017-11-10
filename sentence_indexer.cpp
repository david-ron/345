/*
 * sentence_indexer.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: David
 */

#include "sentence_indexer.h"
/*!
 * allows for insetering of new string to create sentence objects
 */
sentence_indexer & operator >> (sentence_indexer & left,string right)
{
sentence_token t = sentence_token(right);
	vector<string> tmpsentences;
	tmpsentences=t.sentencetoken();
	for(unsigned int i= 0; i <tmpsentences.size();++i){
		sentence tmp = sentence(tmpsentences[i],t.getPos()[i],left.docCount,right);
	left.sentenceObj.push_back(tmp);
	}
	left.numofSen += (left.sentenceObj.size()-left.numofSen);
	left.docCount++;
	return left;
}
/*!
 * default constructor
 */
sentence_indexer::sentence_indexer():docCount(0),numofSen(0){}


/*!
 *finds weights of data
 */
void sentence_indexer::normalize()
{

    double tempidf = 0;
    double temptf = 0;
    double weight = 0.00;
    vector<double> d_weight;
    vector<double> empty;
    double doc = numofSen;
    vector<string> diction = dictionary.getTokens();
    for(unsigned int i=0; i<tf[0].size();++i)
    {
        for(unsigned int j=0; j<tf.size();++j)
        {
            double ttf = (double)(tf[j][i]);
            if(ttf != 0&&df[i]!=doc)
            {
                tempidf = log(doc/df[i]);
                temptf = (1+log(tf[j][i]));
                weight = tempidf*temptf;

                d_weight.push_back( floorf(weight * 1000) / 1000);

            }
            else
            {
                d_weight.push_back(0);
            }
        }
        tf_idf_weights.push_back(d_weight);
        d_weight = empty;


    }


}

/*!
 * finds the score of a sentence
 */
vector<double> sentence_indexer::score()
{
		double accum = 0., norm = 0.;
		vector<double> norms;

		for(unsigned int i =0 ;i<tf_idf_weights.size();++i)
		{
			for(unsigned int j =0 ;j<tf_idf_weights[0].size();++j){
			accum += tf_idf_weights[j][i]*tf_idf_weights[j][i];
			}
			if(accum==0){
				norms.push_back(0);}
			else{
			norms.push_back(accum);
			accum = 0;}
		}
		for(unsigned int i =0 ;i<tf_idf_weights.size();++i){
			norms[i] = sqrt(norms[i]);
		}

		for(unsigned int i =0 ;i<tf_idf_weights.size();++i)
			{
		        accum += tfquery_idf_weight[i] * tfquery_idf_weight[i];
			}
		norm = sqrt(accum);
		double topdot=0;
		vector<double> total_top;
		double tmp1 = 0., tmp2 = 0.;
		for(unsigned int i =0 ;i<tf_idf_weights[0].size();++i)
			{
				for(unsigned int j =0 ;j<tf_idf_weights.size();++j)
				{
					tmp1 = tfquery_idf_weight[j];
					tmp2 = tf_idf_weights[j][i];
					topdot += tmp1*tmp2;
				}
				total_top.push_back(topdot);
				topdot = 0;
			}
		double tmp3 = 0.;
		vector<double> results;
		for(unsigned int i =0 ;i<tf_idf_weights[0].size();++i)
			{
					tmp1 = norm;
					tmp2 = norms[i];
					tmp3 = total_top[i];
//					cout<<tmp1<< "  "<<tmp2<<"  "<<tmp3<<"    \n";
					if(tmp1==0||tmp2==0||tmp3==0){
						results.push_back(0);}
					else{
					results.push_back(tmp3/(tmp1*tmp2));}
			}

		return results;

}



	/*!
	 + * @param dictionary
	 + * Printing out the result in the good format
	 + */
void sentence_indexer::print(index_item & dictionary) {

		string longWord;
		int longWordNum;

		string tempLong="";
		for (unsigned int i = 0; i < dictionary.getTokens().size(); ++i) {
			if( dictionary.getTokens()[i].size() > tempLong.size())
			{
				tempLong = dictionary.getTokens()[i];
			}

			longWord = tempLong;
			longWordNum = longWord.size();
		}


		string tmd ="DOC";
		string temps="";
		cout<<left<<setw(2*longWordNum + 20) << "";
		for (unsigned int a =0; a <tf.size(); ++a){
			temps= to_string(a);
			tmd = tmd + temps;
			cout << left << setw(longWordNum + 10) << tmd;
			tmd="DOC";
		}

		cout<<endl;

		 cout<<setw(longWordNum + 10) <<"DICTIONARY";

		 for (unsigned int k = 0; k < tf.size(); ++k) {

		        if (k == 0) {
		            cout << left <<setw(longWordNum + 10) << "DF";
		            cout<<setw(longWordNum + 10)<<"TF";
		        } else {
		            cout << left << setw(longWordNum + 10) << "TF";
		        }

		    }

		cout<<endl;

		   for (unsigned int i = 0; i < dictionary.getTokens().size(); ++i) {

		        for (unsigned int j = 0; j < tf.size(); ++j) {

		            if(j==0){
		                cout << left<<setw(longWordNum + 10) << dictionary.getTokens()[i];
		            cout<<setw(longWordNum + 10)<< df[i];
		                cout<<setw(longWordNum + 10)<<  tf[j][i];}
		            else{
		                cout << setw(longWordNum + 10) << tf[j][i];
		            }

		        }
		        cout<<endl;

		    }

		cout<<endl;
		cout<<"Weight Printing"<<endl;

		for(unsigned int j=0; j<tf.size();++j)
		{
			for(unsigned int i=0; i<tf[0].size();++i)
			{
				cout<< setw(5) << tf_idf_weights[i][j]<< "  ";
			}
			cout<<endl;
		}
}
/*!
 * takes in a string question to find relevant sentences to produce an essay with
 */
vector<query_result> sentence_indexer::query(string str, int x){
    vector<string> words;
    sentence_token t = sentence_token();
    words = t.removeSpace(str);
    querytfFinder(words);
    normalizequery();
    vector<double> scores = score();
    query_result qr = query_result();
    vector<query_result> qrs;
    for(unsigned int i = 0 ; i<sentenceObj.size();++i)
    {
    	scores[i] = scores[i]- (int)scores[i];
        qr = query_result(sentenceObj[i],scores[i]);
        cout<<sentenceObj[i].getdocNum()<< sentenceObj[i].getName() <<" doc num score  "<<scores[i]<<endl;
        qrs.push_back(qr);
    }
    sort(qrs.begin(),qrs.end(),query_result::scorecomp);
    vector <query_result> final;
    int size = 0;
    for(unsigned int i =0; i<30&&size <x;){
    	final.push_back(qrs[i]);
    	size += (qrs[i].getItem().getTokens()).size()-i;
    	i++;
    }
  	vector<index_item> tmp;
    	for(unsigned int i = 0 ; i<final.size();++i){
    		tmp.push_back(final[i].getItem());
    	}
    	sort((tmp.begin()),tmp.end(),index_item::positioncomp);
    	for(unsigned int i = 0 ; i<tmp.size();++i){
    		for(unsigned int j = 0; j<tmp[i].getTokens().size();++j){

    			cout<<tmp[i].getTokens()[j]<< " ";
    		}
    		cout<<endl;
    	}
    return final;
}
/*!
 * return pointer to index item
 */
index_item* sentence_indexer::operator[](int i){
	index_item* p = dynamic_cast<index_item*>(&sentenceObj[i]);
	return p;
}
/*!
 * retursn the number of sentences there are
 */
int sentence_indexer::getnumofSen(){
	return numofSen;
}
/*!
 * allows user to attach dictionary to the sentence indexer object
 */
void sentence_indexer::setdictionary(index_item& dict)
{

dictionary.setTokens(dict.getTokens());
}
/*!
 * finds the document frequency and term frequency
 */
void sentence_indexer::dftfFinder(index_item & dictionary)
{
	double count=0;
	    vector<double> counter;
	    vector<double> empty;
	    int temp;
	    for(unsigned int n0=0; n0 < sentenceObj.size(); ++n0) {
	        for (unsigned int n1 = 0; n1 < dictionary.getTokens().size(); ++n1) {
	            temp = sentenceObj[n0].getMap()[dictionary.getTokens()[n1]];
	            counter.push_back(temp);
	            count = 0;
	        }
	        tf.push_back(counter);
	        counter = empty;
	    }
	    int ctr = 0;
	    for (unsigned int n1 = 0; n1 < dictionary.getTokens().size(); ++n1)  {
	          for(unsigned int n0=0; n0 < sentenceObj.size(); ++n0)  {
	              temp = sentenceObj[n0].getMap()[dictionary.getTokens()[n1]];
	              if(temp>0){
	            	 ++ctr;}
	          }
	          df.push_back(ctr);
	          ctr =0;
	      }
}
/*!
 * finds the term frequency of said query
 */
void sentence_indexer::querytfFinder(vector<string> str)
{
    double count=0;
    vector<double> empty;
    vector<string> diction = dictionary.getTokens();
    vector<string> temp;
    for (unsigned int i = 0; i < diction.size(); ++i) {

        for(unsigned int j = 0; j<str.size();++j) {

            if (str[j] == diction[i])
            {
                ++count;
            }
        }

        tfquery.push_back(count);
//        cout<<tfquery[i]<<endl;
        count = 0;
    }

}
/*!
 * find the weights query
 */
void sentence_indexer::normalizequery()
{
    double weight=0;
    vector<double> d_weight;
    double tempidf=0,temptf=0;
    double tmp=0;
    double floor = 0;
    for(unsigned int i=0; i<tfquery.size();++i)
    {

        tmp = tfquery[i];
        if(tmp==0)
        {
            tfquery_idf_weight.push_back(0);
        }
        else
        {
            tempidf = log10(numofSen/df[i]);
            temptf = (1+log10(tfquery[i]));
            weight = tempidf*temptf;
            floor =floorf(weight * 100) / 100;
            tfquery_idf_weight.push_back(floor);
        }
    }

}
/*!
 *
 * @param os
 * @param idx
 * @return
 */
ostream & operator <<(ostream & os , sentence_indexer & right)
{
    if(right.sentenceObj[1].getSize()==-1)
    {
        os<<"error size seems to not be initialized "<<"\n";
    }
    else if(right.sentenceObj[1].getName()=="")
    {
        os<<"seems like there is no file name !!!! :O";
    }
    os<<right.sentenceObj[1].getSize()<< " is the amount of characters in this document\n";
    vector<string> tmpfile ;
    tmpfile = right.sentenceObj[1].getTokens();
    for ( vector<string>::iterator it = tmpfile.begin();it != tmpfile.end(); ++it )
    {
        os<<*it<<"\n";
    }
    return os;
}
