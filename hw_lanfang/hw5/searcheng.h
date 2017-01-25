#ifndef SEARCHENG_H
#define SEARCHENG_H

#include <map>
#include <vector>
#include <string>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
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
   //   std::map<string , MySetWebPage* > ReturnMap();
  // std::map <string, WebPage* > link_map;
  /**** Add other desired member functions here *****/

 private:
  /**** Add other desired data members here *****/
  std::map <string , MySetWebPage* > word_map; //need link_map for the file contents output when clicked
  std::map <string, WebPage* > link_map; //need this for the outputs for accessing incoming and outgoing links
  MySetWebPage all_webpages;

};

#endif
