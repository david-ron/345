//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_INDEX_DOCUMENT_H
#define GOOGLER_INDEX_DOCUMENT_H

#include "index_item.h"
#include <vector>
#include <string>
#include "word_tokenizer.h"
#include <fstream>
#include <algorithm>

using namespace std;

class index_document : public index_item {
    friend std::ostream & operator<<(std::ostream & os, index_document & d);
protected:
    vector<string> filtedTokens;
    double score;
    unordered_map<string,int> tokenMap;
public:
    index_document();
    index_document(string fileName);
    virtual ~index_document();
    string name();
    vector<string> content();
    //will return output stream saying if null or not
    void toCreateDictionary(index_document & doc);
    void sorting();
    void duplicateRemove();

    void changeContent(vector<string> words);
    unordered_map<string,int> getMap();
    void compare(index_document &dict);
    bool scorecomp(const index_document &  left, const index_document & right);
    long findSize();

};


#endif //GOOGLER_INDEX_DOCUMENT_H
