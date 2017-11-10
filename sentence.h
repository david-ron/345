/*
 * sentence.h
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */

#ifndef SENTENCE_H_
#define SENTENCE_H_

#include "index_item.h"
#include "sentence_token.h"
#include "unordered_map"
class sentence : public index_item{
	 friend ostream & operator <<(ostream & os , sentence& right);
public:
	sentence();
	sentence(string sent,int pos,int doc,string fileName);
    void setSize(int newsize);
    int getPos();
    vector<string> getTokens();
    unordered_map<string,int> getMap();
    void duplicateRemove();
    void compare(sentence & sen);
    void toCreateDictionary(index_item *doc);
    int getdocNum();
protected:
    int docNum;
    unordered_map<string,int> senWords;
    double score;


};




#endif /* SENTENCE_H_ */
