//
// Created by Dabu on 2017-11-04.
//

#ifndef GOOGLER_INDEX_ITEM_H
#define GOOGLER_INDEX_ITEM_H

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class index_item {
	friend ostream & operator << (ostream & os, index_item & d);
public:
    index_item();
    index_item(string fileName);
   virtual ~index_item();
    virtual int getSize();
    virtual void setSize(int newsize);
     virtual vector<string> getTokens();
    void setTokens(vector<string> othertok);
    string getName();
    void setName(string newName);
    virtual void setPos(int pos);
   virtual int getPos();
  static bool positioncomp(const index_item & left, const index_item & right) ;

protected:
    vector<string> tokens;
    int size;
    string fileName;
    int pos;

};


#endif //GOOGLER_INDEX_ITEM_H
