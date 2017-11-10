//
//
//#include "stopword.h"
//#include"tokenizer.h"
//#include <algorithm>
//#include <iostream>
//#include <string>
//using namespace std;
//
///*!
// *default constructor
// */
//stopword::stopword() {
//    name  = " ";
//}
//
///*!
// *
// * @param fileName
// * Parametrized constructor
// */
//stopword::stopword(string fileName)
//{
//    name = fileName;
//    Tokenizer *t = new Tokenizer(fileName);
//    sWord = t->tokentoDocument();
//}
///*!
// *
// * @param word
// * + * @return boolean
// + * Overloading the operator () so that if it finds the given word within the vector <string>,
// + * it returns true, else false.
// + * To do so, it iterates through the vector.
// */
//const bool stopword:: operator()(string word)
//{
//    for(vector<string>::const_iterator it = sWord.begin(); it != sWord.end(); ++it)
//    {
//        if(*it == word)
//            return true;
//    }
//    return false;
//}
//
///*!
// + *
// + * @param os
// + * @param sw
// + * @return os
// + * taking in ostream and a stopword
// + * Overload of the operator <<
// + * Output and appropriate message if the given stopword is not initialized properly.
// + * Else, it displays the content of the vector string.
// + */
//
//ostream & operator << (ostream & os, stopword & sw){
//
//                if(sw.name=="")
//            {
//                        os<<"Error, name seems to not be initialized.";
//                    }
//           else if(sw.sWord.empty()){
//               os<<"Error, the vector string seems to not be initialized.";
//           }
//        else {
//                os<<"Here is the content of the vector string:";
//                for (vector<string>::iterator it = sw.sWord.begin(); it != sw.sWord.end(); ++it) {
//
//                                os << *it << "\n";
//                    }
//            }
//        return os;
//   }
//
//*/