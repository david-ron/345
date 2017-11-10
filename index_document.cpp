//
// Created by Dabu on 2017-11-04.
//

#include "index_document.h"


/*!
 *default constructor
 */
index_document::index_document(): index_item()
{
    score=0;
}
/*!
 * destructor
 */
index_document::~index_document(){}
/*!
 *
 * @param fileName
 * constructor that takes a string as parameter and returns a document
 */
index_document::index_document(string fileName){
     setName(fileName);
    word_tokenizer *t = new word_tokenizer(fileName);
    tokens = t->tokentoDocument();
    sort(tokens.begin(),tokens.end());
    string tmpword =""; // needs a custom (private function to clean up :))
    int ctr=1;
    for(vector<string>::iterator it = tokens.begin(); it != tokens.end();++it)
    {
        if(*it==tmpword){
            ctr++;
            tokenMap.insert(make_pair(*it,ctr));
        }
        else{
            tmpword = *it;
            tokenMap.insert(make_pair(*it,ctr));
            ctr = 1;
        }
    }
    this->setSize(findSize());
}

/*!
 *
 * @return
 */
long index_document::findSize()
{
    long count=0;
    for (unsigned int i = 0; i < tokens.size(); ++i) {
        for (unsigned int j = 0; j < tokens[i].size(); ++j) {
            tokens[i].at(j); //Iterates through every character
            count++; //keeps track of number of chars
        }
    }
    return count;
}
/*!
 *
 * @return
 */
vector<string> index_document::content(){
    return tokens;
}
/*!
 *
 */
void index_document::sorting()
{
    sort(tokens.begin(), tokens.end());
}
/*!
 *
 */
void index_document::duplicateRemove()
{
    vector <string> fixedDictionary;
    for (unsigned int i = 0; i < tokens.size()-1; ++i) {
        if(tokens[i]==tokens[i+1]){

        }
        else
            fixedDictionary.push_back(tokens[i]);
    }
    tokens = fixedDictionary;
}
/*!
 *
 * @param doc
 */
void index_document::toCreateDictionary(index_document & doc)
{
    vector<string> words = doc.tokens;
    for (unsigned int i = 0; i < words.size(); ++i)
    {
        tokens.push_back(words[i]);
    }
}
/*!
 *
 * @return
 */

/*!
 *
 * @param words
 */
void index_document::changeContent(vector<string> words)
{
    tokens = words;
}
/*!
 * returns map of index_document
 */
unordered_map<string,int> index_document::getMap(){
    return tokenMap;
}
/*!
 * compares ad removes word from dictionary
 */
void index_document::compare(index_document & dict){

    vector<string> olddict = dict.content();
    vector<string> newdict;
    bool duplicated = false;
    for (unsigned int i = 0; i < olddict.size(); ++i) {
        for (unsigned int j = 0; j < tokens.size(); ++j) {
            if(olddict[i]==tokens[j]){
                duplicated = true;
            }
        }
        if (duplicated==false)
            newdict.push_back(olddict[i]);

        //Resest
        duplicated = false;
    }
    tokens = newdict;
}

/*!
 *
 * @param os
 * @param d
 * @return
 */
ostream & operator << (ostream & os, index_document & d)

{
    if(d.getSize()==-1)
    {
        os<<"error size seems to not be initialized "<<"\n";
    }
    else if(d.fileName=="")
    {
        os<<"seems like there is no file name !!!! :O";
    }
    os  <<  d.getSize() << " is the amount of characters in this document\n";
    for ( vector<string>::iterator it = d.tokens.begin();it != d.tokens.end(); ++it )
    {
        os<<*it<<"\n";
    }
    return os;
}




