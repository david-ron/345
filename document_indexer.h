//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_DOCUMENT_INDEXER_H
#define GOOGLER_DOCUMENT_INDEXER_H

#include "index.h"
#include "index_document.h"
#include "word_tokenizer.h"
#include "query_result.h"
#include "word_tokenizer.h"



class document_indexer : public index {
    friend std::ostream & operator<<(std::ostream & os, document_indexer & idx);
    friend document_indexer & operator>>(document_indexer & left, index_document & right);
private:
    double docCount; //Document Count
    //Similar to our matrix in part 1 holds document that holds tokens of words
    vector<index_document> indexe;
    // to make our 2d matrix of frequency from part 1
    vector<vector<double>> tf;
    vector<double> df;
    vector<vector<double>> tf_idf_weights;
    vector<double> tfquery;
    vector<double> tfquery_idf_weight;
    index_document dictionary;
public:
    const index_document & operator[](const int i);
    document_indexer();
    ~document_indexer();
    int mySize(); //Returns number of documents
    void normalize(); //computes the tf-idf weights based on number of documents
//    to be implemented
    vector<query_result> query(string, int x);
    void dftfFinder(index_document & dictionary);
    // not sure where to place this
    void dictionaryCreation();
    vector<int> getdf();
    void normalizequery();
    void querytfFinder(vector<string> str);
    void indexDictionary(index_document & diction);
    void print(index_item & dictionary);
    vector<double> score();
};


#endif //GOOGLER_DOCUMENT_INDEXER_H
