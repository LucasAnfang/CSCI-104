
#include "mdparser.h"
#include <fstream> 
#include <cctype>
#include <iostream>
using namespace std; 

int main(){
	MySetString allWords;
	MySetString allLinks;
	MDparser parsed_page;
	
	parsed_page.parse("TestingPurposes/supertest.txt", allWords, allLinks);
	cout << "allWords: " << endl;

	for(set<string>::iterator it3 = allWords.begin(); it3!= allWords.end(); ++it3)
	{
		cout << *it3 << endl;
	}
	cout << "allLinks: " << endl;

	for(set<string>::iterator it4 = allLinks.begin(); it4!= allLinks.end(); ++it4)
	{
		cout << *it4 << endl;
	}
}