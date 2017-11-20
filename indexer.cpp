#include"indexer.h"
#include"word_tokenizer.h"
#include"stopword.h"
#include "math.h"
#include<map>

using namespace std;

typedef map<string, map<index_item*, tuple<int, double>>> wordIndexType;

const string SW_FILE = "stopwords.txt";

/**
	Default Constructor
*/
indexer::indexer()
{}

/**
	Destructor that deletes the index_item pointers from the index list
*/
indexer::~indexer()
{
	for (vector<index_item*>::iterator it = indexList.begin();
		it != indexList.end();
		++it)
	{
		delete *it;
	}
}

/**
	Function that returns the number of documents inside the indexer
*/
const int indexer::size() const
{
	return indexList.size();
}

/**
	Function normalize that computes the tf-idf weights
*/
void indexer::normalize()
{
	double N = static_cast<double>(size()); //Total # of documents

	for (wordIndexType::iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		double df = static_cast<double>(it->second.size()); //Document Frequency

		for (map<index_item*, tuple<int, double>>::iterator itt = it->second.begin();
			itt != it->second.end();
			++itt)
		{
			double tf = static_cast<double>(get<0>(itt->second)); //Term Frequency

			get<1>(itt->second) = (1 + log(tf))*log(N / df); //Set tf_idf weight in the map
		}
	}
}

/**
	Function that reads in an index item and adds its content to the wordIndex map
*/
void indexer::operator>>(index_item * item)
{
	indexList.push_back(item);

	word_tokenizer tk(item->content());
	string word;
	while (tk.hasNextToken())
	{
		word = tk.nextToken();
		for (string::size_type i = 0; i != word.length(); ++i)
			word[i] = tolower(word[i]); //Convert characters to lower case
		++get<0>(wordIndex[word][item]); //Increment tf
	}
	normalize();
}

/**
	Function that provides access to the indexed files
*/
index_item * indexer::operator[](int i) const
{
	return indexList[i];
}

/**
	Function that returns a normalized query vector from a given string @param query
*/
map<string, double> indexer::getNormalizedQuery(string query) const
{
	double N = size(); //# of documents/sentences
	double df;
	word_tokenizer tk(query);
	Stopword sw(SW_FILE);
	map<string, double> termWeight;
	string word;

	while (tk.hasNextToken())
	{
		word = tk.nextToken();
		for (string::size_type i = 0; i != word.length(); ++i)
			word[i] = tolower(word[i]); //Convert characters to lower case
		if (!sw(word) && wordIndex.count(word) == 1) /*Ignore stopwords and words not contained in the index*/
			++termWeight[word]; //Temporarily use double value to store the term frequency in the query
	}

	for (map<string, double>::iterator it = termWeight.begin();
		it != termWeight.end();
		++it)
	{
		df = wordIndex.at(it->first).size(); //# of documents/sentences the word appears in
		it->second = (1 + log(it->second))*log(N / df); //Set tf-idf weight where the tf was stored
	}
	
	return termWeight;
}

/**
	Function that computes the cosine similarity between the query vector and the indexed items
*/
std::vector<query_result> indexer::cosineSimilarity(std::map<string, double> termWeight) const
{
	vector<query_result> results;
	double num, qwMagnitude, iwMagnitude, score, weight_q, weight_d;
	string word;
	index_item* doc;

	//Formula is num / (qwMagnitude * iwMagnitude)
	for (int i = 0; i != size(); ++i)
	{ /*For each document/sentence...*/
		num = 0;
		qwMagnitude = 0;
		iwMagnitude = 0;
		doc = (*this)[i];

		for (map<string, double>::const_iterator it = termWeight.begin();
			it != termWeight.end();
			++it) /*For each term in the query...*/
		{
			word = it->first;
			weight_q = it->second;
			qwMagnitude += pow(weight_q, 2);
			if (wordIndex.at(word).count(doc) == 0)
				continue;
			weight_d = get<1>(wordIndex.at(word).at(doc));
			iwMagnitude += pow(weight_d, 2);
			num += weight_q * weight_d;
		}

		if (qwMagnitude == 0 || iwMagnitude == 0) /*Don't divide by 0*/
			score = 0;
		else
			score = num / sqrt(qwMagnitude) / sqrt(iwMagnitude);
		results.push_back(query_result((*this)[i], score));
	}

	return results;
}
