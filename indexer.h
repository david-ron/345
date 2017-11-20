#ifndef INDEXER_H
#define INDEXER_H

#include "index_item.h"
#include "query_result.h"
#include<vector>
#include<map>
#include<string>

class indexer
{
public:
	indexer();
	virtual ~indexer();
	const int size() const; //Number of documents indexed
	void normalize(); //Set tf-idf weights throught the map of words (wordIndex)
	void operator>>(index_item* item); //Read in an index item (document or sentence)
	index_item* operator[](const int i) const;
	virtual std::vector<query_result> query(std::string q, int n) const = 0;
protected:
	std::map<std::string, double> getNormalizedQuery(std::string query) const; //Used in query
	std::vector<query_result> cosineSimilarity(std::map<std::string, double> termWeight) const; //Used in query

	/*****DATA MEMBERS*****/
	std::vector<index_item*> indexList; //List of indexed documents (or sentences)
	std::map<std::string, std::map<index_item*, std::tuple<int, double>>> wordIndex; //Map structure that stores tf and tf-idf
};

#endif
