#include "index_item.h"
#include "word_tokenizer.h"
#include<string>

using namespace std;

/**
	Default Constructor
*/
index_item::index_item()
	:text(""), docName("")
{}

/**
	Constructor that takes as param a new file name @param docName
*/
index_item::index_item(std::string docName)
	:docName(docName)
{}

/**
Default destructor
*/
index_item::~index_item()
{}

/**
	Function that returns the content as string
*/
const string index_item::content() const
{
	return text;
}

/**
	Function that returns the document name as string
*/
const string index_item::name() const
{
	return docName;
}

/**
	Function that adds content to a document @param text
*/
void index_item::setContent(std::string text)
{
	this->text = text;
}
