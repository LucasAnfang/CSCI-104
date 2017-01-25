#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <set>


using namespace std;

string word;
int main (int argc, char * argv[])
{
  set<string> myset; //initialize the set
  ifstream inFile(argv[1]); //gets the textfile name from the command line and prepares the ifstream
  stringstream iss; 
  iss << inFile.rdbuf(); 
  char ch;
  //my implementation goes character by character
  while(iss.get(ch))
  {
    if(ch == ' ')
    {
      iss.get(ch);
      while(ch == ' ') //keeps reading over the extra spaces but doesnt put them to the ofstream
      {
        if(iss.get(ch)) continue;
        else break; //happens at the end of the document
      }
    }

    if(isalpha(ch))
    {   
      char temp; 
      temp = tolower(ch); //sets all characters to lowercase
      word += temp;
      iss.get(ch);
      while(isalpha(ch)) //checks if the next character is an alpha  
      {
        char temp2;
        temp2 = tolower(ch);
        word += temp2;
        if(iss.get(ch)) continue;
        else break; //happens at the end of the document   
      }
      //cout << "|" << word << "|" << endl; //testing
      myset.insert(word);//Add to set
    }
    string temp3;
    word = temp3;
  }
  inFile.close(); //closes the files

  bool check = true;
  while(check)
  {
    cout << "Enter a string and I, the computer, shall check if that string is in the file!" << endl;
    string input;   
    getline(cin, input);
    if(input.empty()) 
    {
      return 1; //ask TA about fixing this so if it is return the program terminates
    }
    transform(input.begin(), input.end(), input.begin(), ::tolower); //changes the input's letters to lowercase
    //cout << "|" << input << "|" << endl; //testing
    if (myset.count(input)!=0) 
    {
      cout << "in the file" << endl;
    }
    else 
    {
      cout << "not in the file" << endl;
    }
  }
}


