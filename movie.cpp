#include "movie.h"
#include<sstream>
#include<fstream>
#include<ostream>
#include<iomanip>
#include<string>
#include<regex>
using namespace std;

	
	movie::movie()
	{}




	//here we take in a movie name as constructor parameter and search the database for that name
	//if we find that name we copy the whole line in a string
	//then we can use regex to extract what we need (id/name/release date)
	movie::movie(string name)
		:movieName(name)
	{
		string line;
		string databasename = "movie.metadata.tsv";
		ifstream ifs(databasename);
	
		size_t pos;

		while (ifs.good())
		{
			getline(ifs,line);
			pos = line.find(name);
			if (pos != string::npos)
			{		
				lineContent += line;
				movieName = name;
				break;
			}
		}
	}

	string movie::getName()
	{
		 return movieName;
	}

	 string movie::getReleaseDate()
	 {
		 
		 //Date format YYYY-MM-DD
		 regex pattern("\\b\\d{4}-\\d{2}-\\d{2}\\b");
		 //Date format YYYY
		 regex pattern2("\\b\\d{4}\\b");
		 smatch match;

		 if(regex_search(lineContent,match,pattern)|| regex_search(lineContent, match, pattern2))
		 for (auto x : match) 
			 {
				 releaseDateMovie = x;
			 }
		 
		 return releaseDateMovie;
	 }


	 //Regex ([^\s]+) looks for anything until white space...in our case will return the movie id 
	 int movie::getID()
	 {
		 regex pattern("[^\\s]+");
		 smatch match;

		 if (regex_search(lineContent, match, pattern))
			 for (auto x : match)
			 {	//Convert string to int ....int x =stoi(stringobj)
				 movieID = stoi(x);
			 }
		 
		 return movieID;
	 }

	
	//Here we search again like in the default constructor, however we search for movie id, that we parce from the line were we found the movie name
	string movie::getContent()
	{
		string line;
		string movieDescriptions = "plot_summaries.txt";
		string movieIDD = to_string(movieID);
		string temp = "";
		size_t pos;


		ifstream ifs(movieDescriptions);
		while (ifs.good())
		{	//converting int to string to be able to use line.find method
			
			getline(ifs, line);
			pos = line.find(movieIDD);
			if (pos != string::npos)
			{
				temp += line;
				break;
			}
		}
		//Removing the id from the content
		contentOfMovie = temp.substr(movieIDD.size());

		return contentOfMovie;
		
	}
	
	std::vector<int> movie::fullMovieList()
	{
		regex pattern("[^\\s]+");
		smatch match;
		
		string line2;
		string databasename = "movie.metadata.tsv";
		ifstream ifs(databasename);



		while (ifs.good())
		{
			getline(ifs, line2);
			
			if (regex_search(line2, match, pattern))
				for (auto x : match)
				{	//Convert string to int ....int x =stoi(stringobj)
					movieNameList.push_back(stoi(x));
				}
		}
		return movieNameList;
	}