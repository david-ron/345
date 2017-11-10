//
//

#include "word_tokenizer.h"

/*!
 *default constructor
 */
word_tokenizer::word_tokenizer():abstract_tokenizer(){}
/*!
 *
 * @param fileName
 * Parametrized constructor
 */
word_tokenizer::word_tokenizer(string s) : abstract_tokenizer(s) {}


/*!
 *
 * @return
 * @return vector<string>
 * This method reads from a file, remove punctuation and insert
 * back the different words into a vector of string.
 * It return that vector at the end.
   */
vector<string> word_tokenizer::tokentoDocument(){

    ifstream ifs(this->getFileName().c_str());
    string word;
    string newWord;
    vector<string> v2;
    if(!ifs){
        cerr << "Error! File not Found" << endl;
    }
    while(ifs>>word){
        newWord = "";
        remove_copy_if(word.begin(), word.end(),
                       back_inserter(newWord),
                       ptr_fun<int, int>(ispunct));

        //Algorithm that converts everything to lower case
        transform(newWord.begin(), newWord.end(), newWord.begin(),::tolower);

        v2.push_back(newWord); //pushes in the fixed words into a vector passed by user.
    }

    return v2;
}
/*!
 + * @param s
 + * @return vector<string>
 + * This methods takes a string and iterate through every character
 + * by checking if it is an space, if so it continues until it reaches a character.
 + * Once it hits one, it keeps of the position of the first character and the last and
 + * insert the corresponding word into the vector string.
 + * Once it has iterate through all the characters, the method return the vector string.
 + */
vector<string> word_tokenizer::removeSpace (string  s) {

    vector<string> tokens;
    unsigned int i = 0;
    unsigned int j = 0;

    while (i != s.size() && j != s.size()) {

        while (i != s.size() && isspace(s[i])){
            ++i;
            j = i;
        }
        while (j != s.size() && !isspace(s[j])) {
            j++;
        }

        if (i != j) {
            tokens.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return tokens;
}
/*!
 + *
 + * @param os
 + * @param t
 + * @return
 + * taking in ostream and a Tokenizer
 + * Overload of the operator <<
 + * Output and appropriate message if the given tokenizer is not initialized properly.
 + * Else, it displays the name of the file.
 + */
ostream & operator << (ostream & os, word_tokenizer & t)
{
    if(t.getFileName()=="")
    {
        os<<"Error, name seems to not be initialized.";
    }
    else{
        os<<"Here is the name of the file of this Tokenizer:"+ t.getFileName() ;
    }
    return os;
}
/*!
 * removes spaces
 */
vector<string> word_tokenizer::removeSpace(vector<string>  strings)
	{
	vector<string> tokens;
	unsigned int i = 0;
	unsigned int j = 0;
	string s;
for(unsigned w = 0 ; w<s.size();++w){
	s = strings[w];
	while (i != s.size() && j != s.size()) {

	    while (i != s.size() && isspace(s[i])){
	        ++i;
	        j = i;
	    }
	    while (j != s.size() && !isspace(s[j])) {
	        j++;
	    }

	    if (i != j) {
	        tokens.push_back(s.substr(i, j - i));
	        i = j;
	    }
	}
}
	return tokens;
}



