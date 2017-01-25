#include "crawler.h"
#include <fstream>
#include <iostream>

using namespace std;

Crawler::Crawler()
{

}

Crawler::~Crawler()
{

}
void Crawler::crawler_add_parse_from_index_file(std::string index_file, PageParser* parser, string path)
{
	ifstream findex;

	findex.open(index_file.c_str());
	string file_in_index;
	if(findex.is_open())
	{
		while(getline(findex, file_in_index))
		{
			if(file_in_index == "") continue;
			else crawler_add_parse_page(file_in_index, parser, path);
		}
	}
	else cout << "Unable to open file" << endl;
}

 void Crawler::crawler_add_parse_page(std::string filename, PageParser* parser, string path)
 {
 		if(link_map.find(filename)!=link_map.end())
	{
		//cout << "skipping " << filename << endl;
		return; // webpage has already been visited
	}
		 ifstream in_file;
	in_file.open((filename).c_str());
		if(in_file.fail())
		{

			in_file.close();

		} 
		else 
		{
			in_file.close();
	WebPage *wp = new WebPage(filename);
	MySet<string> allWords;
	MySet<string> allLinks;
	parser->parse(filename, allWords, allLinks);
	wp->all_words(allWords);
	wp->all_links(allLinks);
	string newPath = path+"/"+wp->filename();
	link_map[filename] = wp;
	CrawlerPages* crawlerPages = new CrawlerPages(wp , newPath);

	pages_discovered.push_back(crawlerPages);
	
	for(set<string>::iterator it2 = allLinks.begin(); it2!= allLinks.end(); ++it2)
    {	
    	crawler_add_parse_page((*it2), parser, newPath);

    }
    }
 }
 void Crawler::populate_file(ostream &out)
 {
 	for(vector<CrawlerPages*>::iterator it2 = pages_discovered.begin(); it2!= pages_discovered.end(); ++it2)
    {
    	out<<(*it2)->getPage()->filename()<<endl;
    }
 }



