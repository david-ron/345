/*
 * movie_exception.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */
#include "movie_exception.h"
/*
  @param e
  constructor
 */
movie_exception::movie_exception(const char* e): index_exception(e){};
/*
 * @param os
 * @param e
 * outputs the exception and the problem related to movie
 */
std::ostream & operator<<(std::ostream &os, const movie_exception &e)
{
	std::cout<< "there an problem in movie " ;
	os<<e.what();
	return os;
};



