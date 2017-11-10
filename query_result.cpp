/*
 * query_result.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: David
 */
#include "query_result.h"

/*!
 *
 */
void query_result::info()
{

	cout<<score<<" "<< doc.getName();
}
/*!
 *default constructor
 */
query_result::query_result(){
	score = 0;
}
/*!
 *
 * @param docc
 * @param scoree
 */
query_result::query_result(index_item & docc,double scoree)
{
	score = scoree;
	doc = docc;
}
/*!
 * boolean based on score
 */
bool query_result::scorecomp(const query_result &  left, const query_result & right){
	return left.score > right.score;
}
/*!
 * returns score of query_result
 */
double query_result::scoree(){
	return score;
}
/*!
 * destructor
 */
query_result::~query_result(){}
/*!
 * returns Index_itemk
 */
index_item query_result::getItem(){
	return doc;
}

