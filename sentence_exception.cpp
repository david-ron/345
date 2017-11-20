/*
 * sentence_exception.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */
#include "sentence_exception.h"
/*
  @param e
  constructor
 */
sentence_exception::sentence_exception(const char* e): index_exception(e){};
/*
 * @param os
 * @param e
 * outputs the exception and the problem related to sentence
 */
std::ostream & operator<<(std::ostream &os, const sentence_exception &e)
{
	std::cout<< "there an problem in sentence " ;
	os<<e.what();
	return os;
};



