#include "query_result.h"
#include<sstream>
#include<iomanip>

using namespace std;

/**
	Default Constructor
*/
query_result::query_result()
	:doc(nullptr), score(0)
{}

/**
	Default Constructor with that accepts a index-item and a double as param  @param item @param sc
*/
query_result::query_result(index_item * item, double sc)
	: doc(item), score(sc)
{}

/**
	Default destructor
*/
query_result::~query_result()
{}

/**
	Function that returns a pointer to the index item of the result
*/
index_item * query_result::getItem() const
{
	return doc;
}

/**
	Function that prints the query result
*/
std::ostream & operator<<(std::ostream & os, const query_result & qr)
{
	ostringstream oss;
	oss << "Document: " << qr.doc->name() << " -> " << setprecision(2) << qr.score;
	return os << oss.str();
}

/**
	Function that compares two query_result objects, used for sorting
*/
const bool operator>(query_result & left, query_result & right)
{
	return (left.score > right.score);
}

/**
	Function that compares two query_result objects, used for sorting
*/
const bool operator<(query_result & left, query_result & right)
{
	return (left.score < right.score);
}