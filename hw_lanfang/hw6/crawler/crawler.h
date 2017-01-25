#ifndef CRAWLER_H
#define CRAWLER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "webpage.h"
#include "pageparser.h"
#include "myset.h"
#include "util.h"
#include "crawlerpages.h"

class Crawler {
public:
	Crawler();
	~Crawler();
	void crawler_add_parse_from_index_file(std::string index_file, PageParser* parser, string path);
  	void crawler_add_parse_page(std::string filename, PageParser* parser, string path);
  	void populate_file(std::ostream &out);

private:
	vector<CrawlerPages*> pages_discovered;
	std::map <string, WebPage* > link_map;
	string path;


};

#endif 