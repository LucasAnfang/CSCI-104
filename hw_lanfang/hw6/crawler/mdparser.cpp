#include "mdparser.h"
#include <fstream> 
#include <cctype>
#include <iostream>
using namespace std; 


void MDparser::parse(string filename, MySet<string>& allWords, MySet<string>& allLinks)
{
	ifstream in_file;
	in_file.open(filename.c_str());
	if(in_file.fail())
	{
		cout << "The file was INVALID" << endl;
		return;
	}

	string line;

	getline(in_file, line);
	while(!in_file.fail())
	{
		string word_temp = "";
		string link_temp = "";
		for(unsigned int i = 0; i < line.length(); i++)
		{
			if(isalnum(line[i]))
			{
				word_temp += line[i];
				if(i==line.length()-1)
				{
					allWords.insert(word_temp);
					//cout << "inserted final word: " << word_temp << endl;
				}
			}
			else if(line[i] == '[')
			{
			   	i++;
			   	while(line[i] != ']')
			   	{
			   	word_temp +=line[i];
			   	i++;
			   	}
			   	allWords.insert(word_temp);
			   	word_temp = "";	
			   	i++;		   
			   	if(line[i]=='(')
			    {
			    i++;
				   	while(line[i] != ')')
				   	{
						link_temp += line[i];

					    i++;
				    }
				    
				  	ifstream testing_file;
				testing_file.open(link_temp.c_str());
				if(testing_file.fail())
				{
		//cout << "The file was INVALID" << endl;
		//return;
				link_temp ="";
				}
				else
				{ 
				allLinks.insert(link_temp);
				link_temp = "";
				}
			    }
			} 
			else
			{
				if(word_temp.size() > 0)
				{
				allWords.insert(word_temp);
				word_temp = "";
				}
			}
		}
		getline(in_file, line);
	}
	in_file.close();
}
