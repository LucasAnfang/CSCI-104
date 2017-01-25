#include "webpage.h"
#include "mdparser.h"
#include <fstream>
#include <iostream>
#include <string>



using namespace std;

WebPage::WebPage()
{

}
WebPage::WebPage(string filename)
{
	file_name = filename;
	MDparser parsed_page;
	parsed_page.parse(filename, words, links);

}
WebPage::~WebPage()
{

}
string WebPage::filename() const
{
	return file_name; 
}
void WebPage::all_words(const MySet<string>& words)
{	
	this->words = (this->words).set_union(words);
}
void WebPage::all_links(const MySet<string>& links)
{	
	this->links = (this->links).set_union(links);
}
MySet<string> WebPage::all_links() const
{
	return links;
}

MySet<string> WebPage::all_words() const
{
	return words;
}

void WebPage::add_incoming_link(WebPage* wp)
{
	(this->in_web_pages).insert(wp);
}
MySet<WebPage*> WebPage::incoming_links() const
{
	return in_web_pages;
}
void WebPage::add_outgoing_link(WebPage* wp)
{
	(this->out_web_pages).insert(wp);
}
MySet<WebPage*> WebPage::outgoing_links() const
{
	return out_web_pages;
}
MySet<string> WebPage::get_links() const
{
	return links;

}
  void WebPage::add_page_rank(double pagerank)
  {
  	pageRank = pagerank;
  }

  double WebPage::page_rank() const
  {
  	return pageRank;
  }
ostream & operator<< (ostream & os, const WebPage & page) //
{
	ifstream in_file;
	in_file.open(page.filename().c_str());
	if(in_file.fail())
	{

		
		return os;
	}
	string line;
	
	getline(in_file, line);
	while(!in_file.fail())
	{

		string word_temp = "";
		for(unsigned int i = 0; i < line.length(); i++)
		{
			if(line[i]=='(')
			{
				i++;
				bool found_it = false;
				while(i < line.length())
				{
					if( line[i] == ')')
					{
						found_it = true;
						break;
					}
					else i++;
				}
				if(!found_it)
				{
					cout << "MALFORMED" << endl;
				}
			}
			else
			{
				word_temp+= line[i];
			}
		}
		os << word_temp << '\n';
		getline(in_file, line);
		word_temp = "";
	}
	in_file.close();	
	return os;

}
