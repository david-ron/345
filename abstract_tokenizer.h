//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_ABSTRACT_TOKENIZER_H
#define GOOGLER_ABSTRACT_TOKENIZER_H

#include <vector>
#include <string>

using namespace std;


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class abstract_tokenizer {
	friend ostream & operator << (ostream & os, abstract_tokenizer & token);
public:
    abstract_tokenizer();
    abstract_tokenizer(string n);
    virtual ~abstract_tokenizer();
   virtual vector<string> removeSpace(string  s) = 0;
    string getFileName();
    void setFileName(string s);
private:
    string fileName;
};


#endif //GOOGLER_ABSTRACT_TOKENIZER_H
