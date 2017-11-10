//
// Created by Dabu on 2017-11-04.
//

#include "index.h"
/*!
 * default constructor
 */
index::index() : count(-1) {}
/*!
 * destructor
 */
index::~index(){}
/*!
 * debug info
 */
ostream & operator << (ostream & os, index & d){
	if(d.count == -1)
		cerr<<"something is missing";
	return os;
}
