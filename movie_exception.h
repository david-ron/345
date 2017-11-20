/*
 * movie_exception.h
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */

#ifndef MOVIE_EXCEPTION_H_
#define MOVIE_EXCEPTION_H_
#include "index_exception.h"
class movie_exception : public index_exception
{
friend std::ostream & operator<<(std::ostream &output, const movie_exception &e);
public:
movie_exception(const char* e);
private:
};




#endif /* MOVIE_EXCEPTION_H_ */
