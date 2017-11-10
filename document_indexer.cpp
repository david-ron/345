//============================================================================
// Name        : document_indexer.cpp
// Author      : David Ronci
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "document_indexer.h"

/*!
 *default constructor
 */
document_indexer::document_indexer():indexe() {}
/*!
 * destructor
 */
document_indexer::~document_indexer(){}
/*!
 *normalizes using tf df to find weights
 */
void document_indexer::normalize()
{

    double tempidf = 0;
    double temptf = 0;
    double weight = 0.00;
    vector<double> d_weight;
    vector<double> empty;
    double doc = docCount;
    vector<string> diction = dictionary.content();
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
 *
 * @param left
 * @param right
 * @return
 */
document_indexer & operator >> (document_indexer & left, index_document & right)
{
    left.indexe.push_back(right);
    left.docCount++;
    return left;
}

/*!
 *
 * @param os
 * @param idx
 * @return
 */
ostream & operator << (ostream & os, document_indexer & idx)
{
    if(idx.indexe[1].getSize()==-1)
    {
        os<<"error size seems to not be initialized "<<"\n";
    }
    else if(idx.indexe[1].getName()=="")
    {
        os<<"seems like there is no file name !!!! :O";
    }
    os<<idx.indexe[1].getSize()<< " is the amount of characters in this document\n";
    vector<string> tmpfile ;
    tmpfile = idx.indexe[1].content();
    for ( vector<string>::iterator it = tmpfile.begin();it != tmpfile.end(); ++it )
    {
        os<<*it<<"\n";
    }
    return os;
}

/*!
 *
 * @param i
 * @return
 */

const index_document & document_indexer::operator[] (const int i)
{
    return indexe[i];
}

/*!
 *
 * @param dictionary
 */
void document_indexer::dftfFinder(index_document & dictionary)
{
    double count=0;
    vector<double> counter;
    vector<double> empty;
    int temp;
    for(unsigned int n0=0; n0 < indexe.size(); ++n0) {
        for (unsigned int n1 = 0; n1 < dictionary.content().size(); ++n1) {
            temp = indexe[n0].getMap()[dictionary.content()[n1]];
            counter.push_back(temp);
            count = 0;
        }
        tf.push_back(counter);
        counter = empty;
    }
    int ctr = 0;
    for (unsigned int n1 = 0; n1 < dictionary.content().size(); ++n1)  {
          for(unsigned int n0=0; n0 < indexe.size(); ++n0)  {
              temp = indexe[n0].getMap()[dictionary.content()[n1]];
              if(temp>0){
            	 ++ctr;}
          }
          df.push_back(ctr);
          ctr =0;
      }
}


/*!
 *
 * @param str
 * @param mode
 * @return
 */
vector<query_result>  document_indexer::query(string str, int x)
{

    vector<string> words;
    word_tokenizer t = word_tokenizer();
    words = t.removeSpace(str);
    querytfFinder(words);
    normalizequery();
    vector<double> scores = score();
    query_result qr = query_result();
    vector<query_result> qrs;
    for(unsigned int i = 0 ; i<scores.size();++i)
    {
//    	scores[i] = scores[i]- (int)scores[i];
        qr = query_result(indexe[i],scores[i]);
        qrs.push_back(qr);
    }
    return qrs;
}
/*!
 * finds score
 */
vector<double> document_indexer::score()
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
				cout<<topdot<<"   \n";
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
					cout<<tmp1<< "  "<<tmp2<<"  "<<tmp3<<"    \n";
					if(tmp1==0||tmp2==0||tmp3==0){
						results.push_back(0);}
					else{
					results.push_back(tmp3/(tmp1*tmp2));}
			}

		return results;

}

/*!
 * allows for a dictionary to be attached to object
 */
void document_indexer::indexDictionary(index_document & diction)
{
    dictionary = diction;
}
/*!
 * finds weights of query
 */
void document_indexer::normalizequery()
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
            tempidf = log10(docCount/df[i]);
            temptf = (1+log10(tfquery[i]));
            weight = tempidf*temptf;
            floor =floorf(weight * 100) / 100;
            cout<<" floor "<<floor<<endl;
            tfquery_idf_weight.push_back(floor);
        }
    }

}
/*!
 *finds the tf of the said query
 */
void document_indexer::querytfFinder(vector<string> str)
{
    double count=0;
    vector<double> empty;
    vector<string> diction = dictionary.content();
    vector<string> temp;
    for (unsigned int i = 0; i < diction.size(); ++i) {

        for(unsigned int j = 0; j<str.size();++j) {

            if (str[j] == diction[i])
            {
                ++count;
            }
        }

        tfquery.push_back(count);
        count = 0;
    }

}
/*!
 + * @param dictionary
 + * Printing out the result in the good format
 + */
void document_indexer::print(index_item & dictionary) {
    string longWord;
    int longWordNum;

    string tempLong="";
    for (unsigned int i = 0; i < dictionary.getTokens().size(); ++i) {
        if( dictionary.getTokens()[i] > tempLong)
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
            cout<< setw(5) <<setprecision(3) <<tf_idf_weights[i][j]<< "  ";
        }
        cout<<endl;
    }
}
