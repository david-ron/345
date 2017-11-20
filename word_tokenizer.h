#ifndef WORD_TOKENIZER_H
#define WORD_TOKENIZER_H

#include "abstract_tokenizer.h"

class word_tokenizer : public abstract_tokenizer
{
public:
	word_tokenizer(std::string content, std::string delimiters = " .,!?:;()`\"");
	~word_tokenizer();
	std::string peekNextToken() override; //returns the next token without removing it from the content
};

#endif
