/*
 * sentence_indexer.h
 *
 *  Created on: Nov 6, 2017
 *      Author: David
 */

#ifndef SENTENCE_INDEXER_H_
#define SENTENCE_INDEXER_H_
#include "sentence.h"
#include "index_item.h"
#include "index.h"

class sentence_indexer : public index{
	 friend sentence_indexer & operator >>(sentence_indexer & left, string right);
	 friend ostream & operator <<(ostream & os , sentence_indexer & right);
public:
	sentence_indexer();
	void normalize();
	vector<double> score();
	void print(index_item & dictionary);
	vector<query_result> query(string str, int x);
	index_item* operator[](int i);
	int getnumofSen();
	void setdictionary(index_item &dict);
	void dftfFinder(index_item & dict);
	void querytfFinder(vector<string> str);
	void normalizequery();
protected:
	vector<sentence> sentenceObj;
	vector<string> sentences;
	int docCount;
	int numofSen;
    vector<vector<double>> tf;
    vector<double> df;
    vector<vector<double>> tf_idf_weights;
    vector<double> tfquery;
    vector<double> tfquery_idf_weight;
    sentence dictionary;
};




#endif /* SENTENCE_INDEXER_H_ */
