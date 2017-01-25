#ifndef WEBPAGE_H
#define WEBPAGE_H
#include <string>
#include <iostream>
#include "myset.h"
using std::string;

class WebPage
{
 public:
  WebPage();

  WebPage(std::string filename);

  ~WebPage();

  /**
   * Sets the filename/URL of this webpage
   */
  void filename(std::string fname);

  /**
   * Returns the filename/URL of this webpage
   */
  std::string filename() const;

  /**
   * Updates the set containing all unique words in the text
   *  with the contents of the input parameter words
   */
  void all_words(const MySet<string>& words);
  void all_links(const MySet<string>& links);
  MySet<string> all_links() const;
  /**
   * Returns all the unique, tokenized words in this webpage 
   */
  MySet<string> all_words() const;

  /**
   * Adds a webpageat links to this page
   */
  void add_incoming_link(WebPage* wp);

  //new
  void add_page_rank(double pagerank);
  double page_rank() const;

  //new

  /**
   * Returns all webpages that link to this page
   */
  MySet<WebPage*> incoming_links() const;

  /**
   * Adds a webpage that this page links to
   */
  void add_outgoing_link(WebPage* wp);

  /**
   * Returns all webpages this page links to
   */
  MySet<WebPage*> outgoing_links() const;

  /**
   * Displays the webpage text to the screen 
   */
   MySet<string> get_links() const;
   

  friend std::ostream & operator<< (std::ostream & os, const WebPage & page);

  /**** Add other desired member functions here *****/

 private:
  double pageRank;
  string file_name;
  MySet<string> words;
  MySet<string> links;
  MySet<WebPage*> in_web_pages;
  MySet<WebPage*> out_web_pages;
  /**** Add other desired data members here *****/

  
};
#endif
