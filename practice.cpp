////============================================================================
//// Name        : practice.cpp
//// Author      : David Ronci
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//using namespace std;
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//#include <cctype>
//#include <fstream>
//int main ()
//{
////	string file ="index.txt";
//	string file ="movie.metadata.tsv";
//	ifstream ifs(file.c_str());
//
//		if(!ifs){
//			cerr << "Error! File not Found" << endl;
//			return 0;
//		}
//	 unsigned char ctr = 0;
//	 char stream;
//	 vector<string> movieToken;
//	 string tmp, tmp2;
//	 unsigned char i = 0,j=0;
//	 ifs >> std::noskipws;
//		while(ifs>>stream)
//		{
//			tmp = tmp + stream;
//			if(((isspace(ifs.peek()))&&ctr==2))
//			{
//				tmp.clear();
//				ctr++;
//			}
//			else if(isspace(ifs.peek())&&ctr==0)
//			{
//
//				ctr++;
//			}
//			else if((isdigit(ifs.peek())&&ctr==3&&isdigit(ifs.peek())&&tmp.size()>4&&!ispunct(tmp[(tmp.size()-2)]))&&!isspace(stream))
//			{
//				ctr++;
//			}
//			else if(ctr==3&&ifs.peek()=='{')
//			{
//				ctr++;
//			}
//			else if(isspace(ifs.peek())&&ctr==5)
//			{
//				ctr++;
//			}
//			else if(stream == '{'){
//						ctr = -1;
//					}
//
//			if(ctr == 1||ctr == 4||ctr==6)
//			{
//
//				if((isdigit(stream)&&tmp.length()<3)||tmp.at(tmp.size()-2)=='.')
//				{
//				ctr=-1;
//				}
//				else if( ctr == 6){
//					cout<<tmp2+tmp<<endl;
//					movieToken.push_back(tmp2+tmp);
//					tmp.clear();
//					ctr++;
//					j++;
//				}
//				else if(ctr ==4){
//					cout<<tmp.substr(1,tmp.size()-3)<<endl;
//					movieToken.push_back(tmp.substr(1,(tmp.size()-3)));
//					ctr++;
//					tmp2 =tmp.at(tmp.size()-1);
//					tmp.clear();
//					j++;
//				}
//				else{
//					cout<<tmp<<endl;
//					movieToken.push_back(tmp);
//					ctr++;
//					tmp.clear();
//					j++;
//				}
//			}
//			if(stream == '\n')
//			{
//				if(ctr == -1||j <3)
//				{
//					if(j==2){
//				cout<<"no date"<<endl;
//				movieToken.push_back("no date");}
//					if(j==1){
//						movieToken.push_back("noName");
//					}
//				}
//				tmp.clear();
//				ctr = 0 ;
//				i++;
//				j =0;
//
//			}
//	//			if(i==30){
//	//				break;
//	//			}
//		}
//		ofstream myfile("test.txt");
//		for(unsigned int i =0; i<movieToken.size();)
//		{
//			myfile << movieToken[i]+ " " + movieToken[i+1] + " " + movieToken[i+2]<<endl;
//			i= i+3;
//		}
//	return 0;
//}
//
//












//	string s = {"hello Tony whats up? I like to eat pumpkin soup Mr. bond. Developed rules of the game. hello."};
//	vector<string> tokens;
//	unsigned int j = 0;
//	string tmp = "";
//	for(unsigned int i = 0 ; i<s.size();++i)
//	{
//		cout<<s.at(i)<<endl;
//		if(s[i] == '.'||s[i] == '!'||s[i] == '?'){
//				if(isspace(s[i-3])&&s[i]=='.'){
//					continue;}
//				else{
//					tmp = s.substr(j,i-j);
//					i++;
//					j=i+1;
//					tokens.push_back(tmp);
//					tmp.clear();
//				}
//		}
//	}
//	cout<<tokens[0]<<"\n";
//	cout<<tokens[1]<<endl;
//	cout<<tokens[2]<<endl;
//	cout<<tokens[3]<<endl;
////	while (i != s.size() && j != s.size()) {
////
////	    while (i != s.size() && isspace(s[i])){
////	        ++i;
////	        j = i;
////	    }
////	    while (j != s.size() && !isspace(s[j])) {
////	        j++;
////	    }
////
////	    if (i != j) {
////	        tokens.push_back(s.substr(i, j - i));
////	        i = j;
////	    }
////	}












//unordered_map<string, int> map;
//map["dog"];
//map["pop"]=1;
//cout<<map["pop"];
//for (auto& x: map) std::cout << " " << x.first << ":" << x.second;
//  std::cout << std::endl;






//vector<double> v = {4,5,5,8,-80,4,5,42,-22};
//	double d=0;
//	double maxSoFar = 0;
//	double maxEndingHere = 0;
//	int maxstart = 0, maxend = 0;
//	for (unsigned int i = 0; i < v.size(); ++i) {
//		if( maxEndingHere + v[i] < 0.0 ) {
//			d = i+1;
//			maxEndingHere = 0.0;
//		} else {
//			maxEndingHere = maxEndingHere + v[i];
//		}
//		if( maxSoFar < maxEndingHere ) {
//			maxstart = d;
//			maxend = i;
//			maxSoFar = maxEndingHere;
//		}
//	}
//	cout<<d<<"  "<<maxstart<<maxend<<"  " <<maxSoFar;
