/*
 * query_exception.h
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */

#ifndef QUERY_EXCEPTION_H_
#define QUERY_EXCEPTION_H_
#include "index_exception.h"
class query_exception : public index_exception
{
friend std::ostream & operator<<(std::ostream &output, const query_exception &e);
public:
query_exception(const char* e);
private:
};




#endif /* QUERY_EXCEPTION_H_ */
