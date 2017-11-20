#ifndef MOVIE_H
#define MOVIE_H


#include<iostream>
#include<fstream>
#include<string>
#include<vector>

class movie
{
public:
	movie();
	movie(std::string movieName);

	std::string getName();
	std::string getContent();
	std::string getReleaseDate();
	int getID();
	std::vector<int> fullMovieList();
private:
	std::string movieName;
	std::string contentOfMovie;
	std::string releaseDateMovie;
	int movieID;
	std::string lineContent;
	std::vector<int> movieNameList;
};

#endif
