#include"abstract_tokenizer.h"
#include"word_tokenizer.h"
#include<string>

using namespace std;

/** Default constructor that has strings as params with @param content @param delimites*/
word_tokenizer::word_tokenizer(string content, string delimiters)
	:abstract_tokenizer(content, delimiters)
{}

/** Destructor */
word_tokenizer::~word_tokenizer() {}

/**Checks the next token word*/
string word_tokenizer::peekNextToken()
{
	size_t pos = 0;
	size_t found = getContent().find_first_of(getDelimiters(), pos);
	while (pos == found) /*while the current character is still a delimiter*/
	{
		++pos;
		found = getContent().find_first_of(getDelimiters(), pos);
		/*increment and check again*/
	}
	return getContent().substr(pos, found - pos); /*If the character position has skipped ahead, there must be a token we can split and return*/
}