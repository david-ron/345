/*
 * summarizer.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */

#include "sentence_indexer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	sentence_indexer to = sentence_indexer();
	to>>"file1.txt";
	to>>"file2.txt";
	to>>"file3.txt";
	//add documents to test (very slow after 2 more documents)
	to>>"FT923-5715";
//	to>>"FT941-14180";
//	to>>"FT923-10880";
//	to>>"FT943-12561";
//	to>>"FT932-15560";
//	to>>"FT944-11244";
//	to>>"FT934-5313";
//	to>>"FT944-8867";
//	to>>"FT941-12953";
//	to>>"FT944-9398";
	sentence dictionary = sentence();

	for(int i = 0 ;i<to.getnumofSen();++i){
		dictionary.toCreateDictionary(to[i]);
	}
	dictionary.duplicateRemove();
	to.dftfFinder(dictionary);
	to.normalize();
	to.setdictionary(dictionary);
//	to.print(dictionary);
	vector<query_result> qrs;
	qrs = to.query("What other factors affect the disputes?",500);
	return 0;
}

