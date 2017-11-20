#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include"index_item.h"
#include<iostream>
#include<fstream>

class query_result
{
public:
	query_result();
	query_result(index_item* item, double sc); //Builds the result of a query for one index_item
	~query_result();
	index_item* getItem() const; //Returns the index_item pointer stored in the result
	friend std::ostream & operator<< (std::ostream & os, const query_result & qr); //Used for printing the results in part 2
	friend const bool operator>(query_result& left, query_result& right); //Used for sorting results by score
	friend const bool operator<(query_result& left, query_result& right);
private:
	index_item* doc;
	double score;
};

#endif