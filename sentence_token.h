/*
 * sentence_token.h
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */

#ifndef SENTENCE_TOKEN_H_
#define SENTENCE_TOKEN_H_
#include "abstract_tokenizer.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>

class sentence_token: public abstract_tokenizer{
public:
	sentence_token();
	sentence_token(string n);
	vector<string> removeSpace(string  s);
	vector<string> sentencetoken();
	vector<int> getPos();
private:
	vector<int> pos;

};




#endif /* SENTENCE_TOKEN_H_ */
