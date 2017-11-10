/*
 * query_result.h
 *
 *  Created on: Oct 18, 2017
 *      Author: David
 */

#ifndef QUERY_RESULT_H_
#define QUERY_RESULT_H_

#include "index_document.h"
#include "sentence.h"
#include <iostream>
using namespace std;

class query_result{
	friend ostream & operator << (ostream & os, query_result & qr);

private:
	index_item doc;
	double score;

public:
	query_result();
	query_result(index_item & docc,double scoree);
	~query_result();
	void info();
	double scoree();
	static bool scorecomp(const query_result &  left, const query_result & right);
	void printEssay();
	index_item getItem();
};

#endif /* QUERY_RESULT_H_ */
