//
// Created by Dabu on 2017-11-04.
//

#include "abstract_tokenizer.h"
/*!
 * default constructor
 */
abstract_tokenizer::abstract_tokenizer():fileName(""){}
/*!
 * creates name in paramterized constructor
 */
abstract_tokenizer::abstract_tokenizer(string n) : fileName(n) {}
/*!
 * gets file name
 */
string abstract_tokenizer::getFileName()
{
	return fileName;
}
/*!
 * holds the file name of item to tokenize
 */
void abstract_tokenizer::setFileName(string s)
{
	fileName = s;
}
/*
 * destructor
 */
abstract_tokenizer::~abstract_tokenizer(){

}
/*!
 * just check if theres an associated filename
 */
ostream & operator << (ostream & os, abstract_tokenizer & token){
	if(token.fileName== ""){
			cerr<<"missing filename";}
		return os;

}
