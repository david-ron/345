/*
 * sentence.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */
#include "sentence.h"
/*!
 * default construct
 */
sentence::sentence():index_item(),docNum(-1),score(-1){
}
/*!
 * paramterized construct
 * @param sent
 * @param npos
 * @param docNum
 * @param fileName
 */
sentence::sentence(string sent,int npos,int docNum,string fileName):index_item(fileName){
	sentence_token t = sentence_token();
	tokens = t.removeSpace(sent);
	for(unsigned int i = 0 ; i<tokens.size();++i){
	senWords[tokens[i]]=(senWords[tokens[i]]+1);}
	setSize(tokens.size());
	this->docNum = docNum;
	this->setPos(npos);
}
/*!
 * set size of sentence
 */
void sentence::setSize(int size){
	size = tokens.size();
}
/*
 * position indocument this sentence lays
 */
int sentence::getPos(){
	return 1;
}
/*
 * the map of words
 */
unordered_map<string,int> sentence::getMap(){
	return senWords;
}
/*
 * the tokens of words
 */
vector<string> sentence::getTokens(){

	return tokens;
}
/*!
 * removes duplicates in the sentence dictionary :)
 */
	void sentence::duplicateRemove()
	{
		 vector <string> fixedDictionary;
		 sort(tokens.begin(),tokens.end());
		    for (unsigned int i = 0; i < tokens.size()-1; ++i) {
		        if(tokens[i]==tokens[i+1]){

		        }
		        else
		            fixedDictionary.push_back(tokens[i]);
		    }

		    tokens = fixedDictionary;
		    for(unsigned int i = 0; i< tokens.size();++i){
		    }

	}
/*!
 * removes extra elements to make a stopword dictionary
 */
void sentence::compare(sentence & sen){

	    vector<string> olddict = sen.tokens;
	    vector<string> newdict;
	    bool duplicated = false;
	    for (unsigned int i = 0; i < olddict.size(); ++i) {
	        for (unsigned int j = 0; j < tokens.size(); ++j) {
	            if(olddict[i]==tokens[j]){
	                duplicated = true;
	            }
	        }
	        if (duplicated==false)
	            newdict.push_back(olddict[i]);

	        //Reset
	        duplicated = false;
	}
	    tokens = newdict;
	}
/*!
 *
 * @param sentence
 * adds words to eventually create dictionary
 */
	void sentence::toCreateDictionary(index_item *doc)
	{
		vector<string> words = doc->getTokens();
		for (unsigned int i = 0; i < words.size(); ++i)
		{
			tokens.push_back(words[i]);
//			cout<<words[i];
		}
	}
/*!
 * returns the number that this object belongs to 0 being first document
 */
    int sentence::getdocNum(){
    	return docNum;
    }
    /*!
     *
     * @param os
     * @param idx
     * @return
     */
    ostream & operator <<(ostream & os , sentence& right){
    	if(right.docNum==0||right.fileName==""||right.pos==0||right.score==0||right.size==-1)
    		cerr<<"something is wrong :(";
    	return os;
    }
