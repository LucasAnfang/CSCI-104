#include "searcheng.h"
#include <iostream>
#include <fstream>
#include "webpage.h"

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
	for(map<string, MySet<WebPage*>*>::iterator it1 = word_map.begin(); it1!= word_map.end(); ++it1)
	{
		delete (it1->second);
	}
}



MySet<WebPage*>& SearchEng::get_all_webpages()
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
			//cout << "hmmmmmmm" << endl;
		}
	}
	else cout << "Unable to open file" << endl;
}
  
void SearchEng::add_parse_page(string filename, PageParser* parser) 
{

	if(link_map.find(filename)!=link_map.end())
	{
		//cout << "skipping " << filename << endl;
		return; // webpage has already been visited
	}

	WebPage *wp = new WebPage(filename);
	MySet<string> allWords;
	MySet<string> allLinks;
	parser->parse(filename, allWords, allLinks);
	wp->all_words(allWords);
	wp->all_links(allLinks);
	all_webpages.insert(wp);
	link_map[filename] = wp;
	
	for(set<string>::iterator it2 = allWords.begin(); it2!= allWords.end(); ++it2)
    {
      string key = convToLower(*it2);
      if(word_map.find(key)==word_map.end())
      {
        MySet<WebPage*>* new_page_set = new MySet<WebPage*>();
        word_map[key] = new_page_set;
      }
      MySet<WebPage*>* new_page_set = word_map[key];
      new_page_set->insert(wp);
    }
	for(set<string>::iterator it2 = allLinks.begin(); it2!= allLinks.end(); ++it2)
    {	
    	add_parse_page((*it2), parser);

	//(link_map[(*it2)])->add_incoming_link(wp);

	ifstream in_file;
		//cout << "post1" << endl;
	in_file.open((*it2).c_str());

	//cout << "post2" << endl;

		if(in_file.fail())
		{
			//cout << "shoot" << endl;

			in_file.close();
			//allLinks.erase(*it2);
			//return;
		} 
		else 
		{
				(link_map[(*it2)])->add_incoming_link(wp);
			wp->add_outgoing_link(link_map[(*it2)]);
		}
    }
}

MySet<WebPage*> SearchEng::and_method(vector<string> query_words)
{
	MySet<WebPage*> bucket_of_webpages;
	MySet<WebPage*> pre_comparison_webpage_list;
	pre_comparison_webpage_list = bucket_of_webpages.set_union(all_webpages);
	MySet<WebPage*> comparison_webpage_list;

	for(vector<string>::iterator it4 = query_words.begin(); it4 != query_words.end(); it4++)
	{
		pre_comparison_webpage_list = one_word_helper_method(*it4).set_intersection(pre_comparison_webpage_list);
	}
	for(set<WebPage*>::iterator it1 = pre_comparison_webpage_list.begin(); it1 != pre_comparison_webpage_list.end(); it1++)
	{
		//cout << "hmmm    " << endl;
		comparison_webpage_list.insert(*it1);
		MySet<WebPage*> files_incoming_links((*it1)->incoming_links());

		if((*it1)->incoming_links().size()>0)
		{
			for(set<WebPage*>::iterator it2 = files_incoming_links.begin(); it2 != files_incoming_links.end(); it2++)
			{
				//cout << "testing 1" 
				comparison_webpage_list.insert(*it2);
				//cout << (*it1)->filename() << "'s incoming link " << (*it2)->filename();
			}
		}
		MySet<WebPage*> files_outgoing_links((*it1)->outgoing_links());
		if((*it1)->outgoing_links().size()>0)
		{
			for(set<WebPage*>::iterator it3 = files_outgoing_links.begin(); it3 != files_outgoing_links.end(); it3++)
			{
				comparison_webpage_list.insert(*it3);
				//cout << (*it1)->filename() << "'s incoming link " << (*it3)->filename();
			}
		}
	}
	return comparison_webpage_list;
}

MySet<WebPage*> SearchEng::or_method(vector<string> query_words)
{	
	MySet<WebPage*> pre_comparison_webpage_list;
	MySet<WebPage*> comparison_webpage_list;
	for(vector<string>::iterator it4 = query_words.begin(); it4 != query_words.end(); it4++)
	{
		pre_comparison_webpage_list = (one_word_helper_method(*it4).set_union(pre_comparison_webpage_list));
	}
	for(set<WebPage*>::iterator it1 = pre_comparison_webpage_list.begin(); it1 != pre_comparison_webpage_list.end(); it1++)
	{
		//cout << "hmmm    " << endl;
		comparison_webpage_list.insert(*it1);
		MySet<WebPage*> files_incoming_links((*it1)->incoming_links());

		if((*it1)->incoming_links().size()>0)
		{
			for(set<WebPage*>::iterator it2 = files_incoming_links.begin(); it2 != files_incoming_links.end(); it2++)
			{
				//cout << "testing 1" 
				comparison_webpage_list.insert(*it2);
				//cout << (*it1)->filename() << "'s incoming link " << (*it2)->filename();
			}
		}
		MySet<WebPage*> files_outgoing_links((*it1)->outgoing_links());
		if((*it1)->outgoing_links().size()>0)
		{
			for(set<WebPage*>::iterator it3 = files_outgoing_links.begin(); it3 != files_outgoing_links.end(); it3++)
			{
				comparison_webpage_list.insert(*it3);
				//cout << (*it1)->filename() << "'s incoming link " << (*it3)->filename();
			}
		}
	}

	return comparison_webpage_list;
}

MySet<WebPage*> SearchEng::one_word_method(string query_word)
{
	map <string , MySet<WebPage*>* >::iterator it3;
	string input_key = convToLower(query_word);
	MySet<WebPage*> comparison_webpage_list;
	if(word_map.find(input_key)==word_map.end())
    {
    	MySet<WebPage*> empty_webpage;
    	return empty_webpage;
    }
    else
    {
    	it3 = word_map.find(input_key);
    	//return *(it3->second);
		//cout << "hmmm    " << endl;
		for(set<WebPage*>::iterator it5 = (*(it3->second)).begin(); it5 != (*(it3->second)).end(); it5++)
		{
			comparison_webpage_list.insert(*it5);
			MySet<WebPage*> files_incoming_links((*it5)->incoming_links());

			if((*it5)->incoming_links().size()>0)
			{
				for(set<WebPage*>::iterator it2 = files_incoming_links.begin(); it2 != files_incoming_links.end(); it2++)
				{
					//cout << "testing 1" 
					comparison_webpage_list.insert(*it2);
					//cout << (*it1)->filename() << "'s incoming link " << (*it2)->filename();
				}
			}
			MySet<WebPage*> files_outgoing_links((*it5)->outgoing_links());
			if((*it5)->outgoing_links().size()>0)
			{
				for(set<WebPage*>::iterator it4 = files_outgoing_links.begin(); it4 != files_outgoing_links.end(); it4++)
				{
					comparison_webpage_list.insert(*it4);
					//cout << (*it1)->filename() << "'s incoming link " << (*it3)->filename();
				}
			}
		}
		return comparison_webpage_list;
    }
}

MySet<WebPage*> SearchEng::one_word_helper_method(string query_word)
{
	map <string , MySet<WebPage*>* >::iterator it3;
	string input_key = convToLower(query_word);
	if(word_map.find(input_key)==word_map.end())
    {
    	MySet<WebPage*> empty_webpage;
    	return empty_webpage;
    }
    else
    {
    	it3 = word_map.find(input_key);
    	return *(it3->second);
    }
}
