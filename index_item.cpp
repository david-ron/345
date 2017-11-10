//
// Created by Dabu on 2017-11-04.
//

#include "index_item.h"
/*!
 * default for size and filename
 */
index_item::index_item() : size(0),fileName(""),pos(-1){ }
/*!
 * allows addition of name
 */
index_item::index_item(string Name) : size(0),fileName(Name),pos(){ }
/*!
 * @return size
 */
int index_item::getSize() {
    return size;
}
/*!
 * changes
 */
void index_item::setSize(int newsize){
	size = newsize;
}
/*!
 * destructor
 */
index_item::~index_item(){}
/*!
 *
 */
vector<string> index_item::getTokens(){
	return tokens;
}
/*!
 * set the tokens
 */
void index_item::setTokens(vector<string> othertok)
{
	tokens = othertok;
}
/*!
 * @return fileName
 */
string index_item::getName(){
	return fileName;
}
/*!
 * sets fileName
 */
 void index_item::setName(string newName)
 {
	 fileName = newName;
 }
 /*
  * sets new @varable pos
  */
 void index_item::setPos(int npos)
 {
	 pos = npos;
 }
 /*!
  * @param pos
  */
 int index_item::getPos(){
	 return pos;
 }
 /*!
  * compares position and document name
  */
 bool index_item::positioncomp(const index_item & left, const index_item & right){
	 if(left.fileName != right.fileName)
	 return left.fileName> right.fileName;
	 return left.pos>right.pos;
 }
 /*!
  * DEBUG INFO
  */
 ostream & operator << (ostream & os, index_item & d){
	 if(d.pos == -1||d.size ==0 ||d.fileName=="")
		 std::cerr<<"something is missing :(";
	 return os;
 }
