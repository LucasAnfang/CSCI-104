#include "searcheng.h"
#include <iostream>
#include <fstream>
using namespace std;

SearchEng::SearchEng()
{

}

SearchEng::~SearchEng()
{
	for(set<WebPage*>::iterator it1 = all_webpages.begin(); it1!= all_webpages.end(); ++it1)
	{
		delete (*it1);
	}
	for(map<string, MySetWebPage*>::iterator it1 = word_map.begin(); it1!= word_map.end(); ++it1)
	{
		delete (it1->second);
	}
}

MySetWebPage& SearchEng::get_all_webpages()
{
	return all_webpages;
}

void SearchEng::add_parse_from_index_file(string index_file, PageParser* parser)
{
	ifstream findex;
	findex.open(index_file.c_str());
	string file_in_index;
	if(findex.is_open())
	{
		while(getline(findex, file_in_index))
		{
			if(file_in_index == "") continue;
			else add_parse_page(file_in_index, parser);
		}
	}
	else cout << "Unable to open file" << endl;
}
  
void SearchEng::add_parse_page(string filename, PageParser* parser) 
{
	WebPage *wp = new WebPage(filename);
	MySetString allWords;
	MySetString allLinks;
	parser->parse(filename, allWords, allLinks);
	wp->all_words(allWords);
	wp->all_links(allLinks);
	all_webpages.insert(wp);
	
	for(set<string>::iterator it2 = allWords.begin(); it2!= allWords.end(); ++it2)
    {
      string key = convToLower(*it2);
      if(word_map.find(key)==word_map.end())
      {
        MySetWebPage* new_page_set = new MySetWebPage();
        word_map[key] = new_page_set;
      }
      MySetWebPage* new_page_set = word_map[key];
      new_page_set->insert(wp);
    }
}

MySetWebPage SearchEng::and_method(vector<string> query_words)
{
	MySetWebPage bucket_of_webpages;
	MySetWebPage comparison_webpage_list;
	comparison_webpage_list = bucket_of_webpages.set_union(all_webpages);

	for(vector<string>::iterator it4 = query_words.begin(); it4 != query_words.end(); it4++)
	{
		comparison_webpage_list = one_word_method(*it4).set_intersection(comparison_webpage_list);
	}
	return comparison_webpage_list;
}

MySetWebPage SearchEng::or_method(vector<string> query_words)
{	
	MySetWebPage comparison_webpage_list;
	for(vector<string>::iterator it4 = query_words.begin(); it4 != query_words.end(); it4++)
	{
		comparison_webpage_list = (one_word_method(*it4).set_union(comparison_webpage_list));
	}
	return comparison_webpage_list;
}

MySetWebPage SearchEng::one_word_method(string query_word)
{
	map <string , MySetWebPage* >::iterator it3;
	string input_key = convToLower(query_word);
	if(word_map.find(input_key)==word_map.end())
    {
    	MySetWebPage empty_webpage;
    	return empty_webpage;
    }
    else
    {
    	it3 = word_map.find(input_key);
    	return *(it3->second);
    }
}
