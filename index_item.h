#ifndef ITEM_INDEX_H
#define ITEM_INDEX_H

#include<string>
#include "abstract_tokenizer.h"
class index_item
{
public:
	index_item();
	index_item(std::string docName); //Create index item from document name
	virtual ~index_item();
	virtual const int size() const = 0;
	const std::string content() const; //Return content (sentence of whole document) of index item
	const std::string name() const; //Return name of document (or containing document for sentence)
protected:
	void setContent(std::string text); //Setter for derived classes
private:
	std::string text;
	std::string docName;
};

#endif
