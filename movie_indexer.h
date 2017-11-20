/*
 * movie_indexer.h
 *
 *  Created on: Nov 20, 2017
 *      Author: David
 */
#include "indexer.h"
#include "movie.h"
class movie_indexer : public indexer
{
public:
	movie_indexer();
	~movie_indexer();
	movie_indexer(std::string plot); //Creates an indexed set of movies from the files in indexFile
	std::vector<query_result> query(std::string q, int n = 5) const override; //Queries for the most relevant movies up to n words, sorted
	friend const bool topRecommendation(query_result left, query_result right); //Used to sort the results
private:

};
