/*
 * index_exception.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: David
 */
#include "index_exception.h"
#include <typeinfo>
/*
 * default constructor
 */
index_exception::index_exception():problem(){};
/*
 * constructor that takes in a parameter to use to return the exception message @param problem
 */
index_exception::index_exception(const char* error): problem(error){};
/*
 * returns problem via char *
 */
const char * index_exception::what()const noexcept
{

	return problem;
}
/*
 * @param os
 * @param e
 * produces problem related to more of a index item
 */
std::ostream & operator<<(std::ostream &os, const index_exception &e){
	std::cout<<" there is a problem with with index item ";
	os<<e.what();
	return os;
}
