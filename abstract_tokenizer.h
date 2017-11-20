#ifndef ABSTRACT_TOKENIZER_H
#define ABSTRACT_TOKENIZER_H

#include<string>

class abstract_tokenizer
{
public:
	abstract_tokenizer(std::string content, std::string delimiters);
	virtual ~abstract_tokenizer();
	const std::string getContent() const;
	const std::string getDelimiters() const;
	bool hasNextToken(); //Checks if there is another token to split in the structure
	virtual std::string peekNextToken() = 0; //returns the next token without removing it from the content
	std::string nextToken(); //returns the next token and removes it from the content
protected:
	void setContent(std::string cont);
private:
	std::string content; //the content of the structure being worked on
	std::string delimiters; //delimiters (default or chosen with constructor)
};

#endif
