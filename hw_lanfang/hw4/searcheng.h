#ifndef SEARCHENG_H
#define SEARCHENG_H

#include <map>
#include <vector>
#include <string>
#include "webpage.h"
#include "myset.h"
#include "pageparser.h"
#include "util.h"

class SearchEng {
 public:
  SearchEng();
  ~SearchEng();
  void add_parse_from_index_file(std::string index_file, PageParser* parser);
  void add_parse_page(std::string filename, PageParser* parser);
  MySetWebPage and_method(std::vector<string> query_words);
  MySetWebPage or_method(std::vector<string> query_words);
  MySetWebPage one_word_method(std::string query_word);  
  MySetWebPage& get_all_webpages();
  /**** Add other desired member functions here *****/

 private:
  /**** Add other desired data members here *****/
  std::map <string , MySetWebPage* > word_map;
  MySetWebPage all_webpages;
};

#endif
