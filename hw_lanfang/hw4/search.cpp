#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream> 
#include <cctype>
#include <sstream>
#include <locale>

#include "webpage.h"
#include "searcheng.h"
#include "mdparser.h"
#include "util.h"

using namespace std;

void display_results(set<WebPage*>& results);

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "usage: ./search index_file...Please provide an index file" << endl;
    return 1;
  }
  /****************   Add code to ***************************/
  /* Initialize your search engine and parse all the pages */
  // read index file and create a set of webpages 
  // check set of webpages is not NULL
  // call display result on parsed pages for testing purposes
  // Go into loop down below 
  PageParser *parser = new MDparser();
  MySetWebPage result;
  string index_filename;
  index_filename = argv[1];
  SearchEng my_engine;
  my_engine.add_parse_from_index_file(index_filename, parser);
  //display_results(my_engine.get_all_webpages());

  string myline;
  bool done = false;
  while( !done ){
    cout << "\n++++++++++++++++++++" << endl;
    cout << "Enter search terms: " << endl;
    getline(cin, myline);
    cout << "++++++++++++++++++++\n" << endl;
    istringstream iss(myline);
    vector<string> query_words;
    string word_type;
    iss>>ws>>word_type;
    string single_word = "";
    string new_word = "";
    string query_word = "";

    if(word_type == ".")
    {
      done = true;
      continue;
    }
    else
    {
      word_type = convToLower(word_type);
      if(word_type == "and")
      {
        while(iss>>ws>>new_word)
        {
          query_words.push_back(new_word);     
        }
        //call OR fn
        if(query_words.size() >= 1)
        {
        result = my_engine.and_method( query_words);
        }
        else 
        {
          cout << "malformed entry" << endl;
          continue;
        }
      }
      else if(word_type == "or")
      {
        while(iss>>ws>>new_word)
        {
          query_words.push_back(new_word);
        }      
        //call AND fn
        if(query_words.size() >= 1)
        {
        result = my_engine.or_method( query_words);
        }
        else 
        {
          cout << "malformed entry" << endl;
          continue;
        }
      }
      else 
      {
        string test = "";
        iss>>ws>>test;
        if(test != "")
        {
          cout << "Malformed entry" << endl;
          continue;
        }      
        query_word = word_type;
        result = my_engine.one_word_method(query_word);
      }
    }
    /* Add your code here and feel free to modify    */
    /*  what is above but don't change the display.  */
    /* Call display_results() with the set of pages  */
    /*  that match the search. It will display the   */
    /*  matching results to the screen for you.      */
    // check that myline is not a single dot 
    // trim off all the white space 
    //        set done = true  and put continue; 
    // if not done see if they entered a single word, AND case or OR case
    // otherwise it is an error (two words no AND or OR) continue 
    // act upon the three cases 
    // word case first 
    // take the first word create a result set (use single word function)
    // loop over all the subsequent word either use intersection or union 
    // this depends on and or or case 
    display_results(result);
  }
  delete parser;
  return 0;
}

void display_results(set<WebPage*>& results)
{
  int hits = results.size();
  cout << hits << " hits." << endl;
  cout << "=====" << endl;
  int i=0;
  for(set<WebPage*>::iterator it = results.begin();it != results.end();++it)
  {
    cout << (*it)->filename() << endl;
    cout << "+---+" << endl;
    cout << (**it) << "\n" << endl;
    i++;
  }  
}
