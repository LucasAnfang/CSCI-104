#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>


using namespace std;


int main (int argc, char * argv[])
{
ifstream inFile(argv[1]); //gets the textfile name from the command line and prepares the ifstream
stringstream iss; 
iss << inFile.rdbuf(); 
ofstream out; //output stream
out.open(argv[2]); 

char ch;
//my implementation goes character by character
while(iss.get(ch))
{
	if(ch == ' ')
	{

		iss.get(ch);
		while(ch == ' ')
		{
			iss.get(ch);  //keeps reading over the extra spaces but doesnt put them to the ofstream
		}
				  
		out.put('\n'); //new line to ofstream

	}

	if(isalpha(ch))
	{		
		out.put(ch);	//checks if the character is an alpha 	
	}

	if(ch == '[') 
	{
		bool linkbool = false;
		string anchor_text;
		while(ch!=']')
		{
			iss.get(ch);
			if(ch==']') //starts the proccess of getting everything in the bracket but onley keeps the alphas in the ofstream
			{
				break;
			}
			else
			{
				if(isalpha(ch))
				{		
					anchor_text+=ch;
					continue;					
				}
			}
		}
		
		iss.get(ch);
		if(ch == '(') //if the parentheses is directly after the bracket it will change the output for the LINK output
		{		
			string link;
			while(ch!=')')
			{
				iss.get(ch);
				if(ch==')')
				{
					break;
				}
				else
				{
					link+=ch;
					continue;
				}
			}
			out << "LINK(";
			out << link;
			out << ","; //sets up the structure of the link output
			out << anchor_text;
			out << ")";
			linkbool = true;
		} //if there is no link it just outputs the anchor text
		if(linkbool==false)
		{
			out << anchor_text;
		}		
	}
	
	if(ch == '(') 
	{
		
		string link;
		while(ch!=')')
		{
			iss.get(ch);

			if(ch==')')
			{
				break;
			}
			else
			{
				link+=ch;
				continue;
			}
		}
		out << "LINK(";
		out << link;
		out << ",";
		out << link; //sets up the structure of the link output
		out << ")";		
	}
}
inFile.close(); //closes the files
out.close();

}
