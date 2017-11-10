/*
 * sentence_token.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */
#include "sentence_token.h"

/*!
 * default construc
 */
sentence_token::sentence_token(): abstract_tokenizer() {}
/*!
 * @param string
 * constructor with param
 */
sentence_token::sentence_token(string n): abstract_tokenizer(n) {}
/*!
 * tokenizes sentences
 */
vector<string> sentence_token::sentencetoken(){

	ifstream ifs(this->getFileName().c_str());
	string word;
	string newWord;
	vector<string> v2;
	int ctr = 1;
	if(!ifs){
		cerr << "Error! File not Found" << endl;
	}
	while(ifs>>word){
		if(ctr == 1){
			newWord = newWord + word;
			++ctr;
		}
		else{
			newWord = newWord+ " " +word;}
	}
	string s = newWord;
	vector<string> tokens;
	unsigned int j = 0;
	string tmp = "";
	for(unsigned int i = 0 ; i<s.size();++i)
	{
		if(s[i] == '.'||s[i] == '!'||s[i] == '?'){
			if(isspace(s[i-3])&&s[i]=='.'){
				continue;}
			else if(isspace(s[i-1])&&isspace(s[i+1])&&s[i] == '.')
			{
				continue;}

			else{
				tmp = s.substr(j,i-j);
				pos.push_back(j);
				i++;
				j=i+1;
				tokens.push_back(tmp);
				tmp.clear();
			}
		}
	}
	return tokens;
}
/*!
 * removes spaces between words
 */
vector<string> sentence_token::removeSpace(string strings)
{
	vector<string> tokens;
	unsigned int i = 0;
	unsigned int j = 0;
	string s = strings;
	string newWord= "";
	//for(unsigned w = 0 ; w<strings.size();++w){
	//	s = strings[w];
	while (i != s.size() && j != s.size()) {

		while (i != s.size() && isspace(s[i])){
			++i;
			j = i;
		}
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}

		if (i != j) {
			if(s.substr(i, j - i)=="-"||s.substr(i, j - i)=="."){
				i = j;
				continue;
			}
		else{
			tokens.push_back(s.substr(i, j - i));
			i = j;}

		}
	}
	//	i= 0;
	//	j = 0;
	//}

	for(unsigned int i = 0 ; i<tokens.size();++i)
	{
		newWord = "";
		remove_copy_if(tokens[i].begin(), tokens[i].end(),
				back_inserter(newWord),
				ptr_fun<int, int>(ispunct));

		//Algorithm that converts everything to lower case
		transform(newWord.begin(), newWord.end(), newWord.begin(),::tolower);
		tokens[i] = newWord;
	}
	return tokens;
}
/*!
 * returns position of position of word
 */
vector<int> sentence_token::getPos(){
	return pos;
}
