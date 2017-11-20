/*
 * query_exception.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */

#include "query_exception.h"
/*
  @param e
  constructor
 */
query_exception::query_exception(const char* e): index_exception(e){};
/*
 * @param os
 * @param e
 * outputs the exception and the problem related to query
 */
std::ostream & operator<<(std::ostream &os, const query_exception &e)
{
	std::cout<< "there an problem in query " ;
	os<<e.what();
	return os;
};




