#include "movie_indexer.h"

const std::string SW_FILE = "stopwords.txt";


/**
	Default constructor
*/
movie_indexer::movie_indexer(){};

/**
	Default destructor
*/
movie_indexer::~movie_indexer(){};

/**
	Constructor that creates a new indexer from movie meta then gets plot info from plot
	@param movieMeta
	@param plot
*/
movie_indexer::movie_indexer(std::string plot)
{
	std::ifstream ifs(plot);
		std::string line;
		std::vector<std::string> docNames;

		while (getline(ifs, line)) /*Get movies to read ID/Date/Title*/
		{
			/*... i can't think of a smart way to do this
			id imagine open plot summary find(ID) corresponding ID in the .tsv file for the attributes
			 &Rest *this>> movie(line)
			*/
			movie mov(line);

		}

};

/*undefinded
 *
 */
std::vector<query_result> movie_indexer::query(std::string q,int n) const
{
	std::vector<query_result> ok;
	return ok;
};
