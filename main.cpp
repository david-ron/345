
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include"movie.h"
#include<string>

using namespace std;

int main() {
	

	movie obj("Taxi Blues");
	
	cout << obj.getID() << endl;
	cout << obj.getName() << endl;
	cout<<obj.getReleaseDate()<<endl;
	cout << "Movie content: " << endl;
	cout << obj.getContent();

	cout << "---------------------------------------------" << endl;

	cout<<obj.fullMovieList().size()<<endl;
	cout << obj.fullMovieList()[81739] << endl;

	return 0; }