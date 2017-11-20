/*
 * sentence_exception.h
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */

#ifndef SENTENCE_EXCEPTION_H_
#define SENTENCE_EXCEPTION_H_

#include "index_exception.h"
class sentence_exception : public index_exception
{
friend std::ostream & operator<<(std::ostream &output, const sentence_exception &e);
public:
sentence_exception(const char* e);
private:
};



#endif /* SENTENCE_EXCEPTION_H_ */
