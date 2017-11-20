/*
 * document_exception.h
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */

#ifndef DOCUMENT_EXCEPTION_H_
#define DOCUMENT_EXCEPTION_H_
#include "index_exception.h"
class document_exception : public index_exception
{
friend std::ostream & operator<<(std::ostream &output, const document_exception &e);
public:
document_exception(const char* e);
private:
};


#endif /* DOCUMENT_EXCEPTION_H_ */
