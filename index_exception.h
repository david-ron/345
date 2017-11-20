/*
 * index_exception.h
 *
 *  Created on: Nov 18, 2017
 *      Author: David
 */

#ifndef INDEX_EXCEPTION_H_
#define INDEX_EXCEPTION_H_
#include <exception>
#include <iostream>
#include <stdexcept>

class index_exception : public std::exception
{
friend std::ostream & operator<<(std::ostream &output, const index_exception &e);
public:
	index_exception();
	index_exception(const char* error);
	const char* what() const noexcept override;
private:
	const char* problem;
};




#endif /* INDEX_EXCEPTION_H_ */
