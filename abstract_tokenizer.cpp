#include<string>
#include<iostream>
#include "abstract_tokenizer.h"

using namespace std;

/** Constructor wtih @param content and @param delimiters */
abstract_tokenizer::abstract_tokenizer(string content, string delimiters)
	: content(content), delimiters(delimiters)
{}


/** Default destructor*/
abstract_tokenizer::~abstract_tokenizer() { }

/** Function that returns the content string*/
const string abstract_tokenizer::getContent() const { return content; }

/** Function that returns the delimiters as strings*/
const string abstract_tokenizer::getDelimiters() const { return delimiters; }

/** Function that sets the content of the tokenizer , @param content */
void abstract_tokenizer::setContent(string cont) { content = cont; }

/** Function that checks if there is another token to split in the structure*/
bool abstract_tokenizer::hasNextToken()
{
	if (peekNextToken() == "")
		return false;
	return true;
}

/** Function that checkes for next token */
string abstract_tokenizer::nextToken()
{
	string token = peekNextToken();
	size_t pos = getContent().find(token, 0);
	setContent(getContent().substr(pos + token.length()));
	return token;
}
