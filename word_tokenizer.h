//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_WORD_TOKENIZER_H
#define GOOGLER_WORD_TOKENIZER_H


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "abstract_tokenizer.h"

class word_tokenizer : public abstract_tokenizer {
	friend ostream & operator << (ostream & os, word_tokenizer & t);
public:
    word_tokenizer();
    word_tokenizer(string s);
    vector<string> tokentoDocument();
    vector<string> removeSpace(string  s);
    vector<string> removeSpace(vector<string> s);
private:
};


#endif //GOOGLER_WORD_TOKENIZER_H
