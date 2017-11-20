#include "stopword.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

/**
*Constructs an object used to check if given words are stopwords from an empty stopword list
*/
Stopword::Stopword()
	:filename("")
{}

/**
*Constructs an object used to check if given words are stopwords
*
*\param fileName is the name of the stopword list file with one stopword per line
*/
Stopword::Stopword(string file)
	:filename(file)
{
	ifstream ifs(filename);

	if (!ifs)
	{
		cerr << "Failed to open " << filename << endl;
		return;
	}
	string line; 
	while (getline(ifs, line))
	{
		swList.push_back(line);
	}
	ifs.close();
}

/*
*Checks if the given \a word is a stopword by comparing it to the vector of stopwords
*
*param word will be identified as a stopword or not
*return true if the word is a stopword, false otherwise
*/
bool Stopword::operator()(string word) const
{
	for (vector<string>::const_iterator it = swList.begin(); it != swList.end(); ++it)
	{
		if (*it == word)
			return true;
	}
	return false;
}