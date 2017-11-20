/*
 * document_exception.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */
#include "document_exception.h"
/*
  @param e
  constructor
 */
document_exception::document_exception(const char* e): index_exception(e){};
/*
 * @param os
 * @param e
 * outputs the exception and the problem related to document
 */
std::ostream & operator<<(std::ostream &os, const document_exception &e)
{
	std::cout<< "there an problem in document " ;
	os<<e.what();
	return os;
};
