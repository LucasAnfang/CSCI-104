#ifndef CRAWLERPAGES_H
#define CRAWLERPAGES_H
#include <string>
#include "webpage.h"

class CrawlerPages {
public:
	CrawlerPages(WebPage* page, string path);
	~CrawlerPages();
	WebPage* getPage();
	std::string getPath();


private:
	WebPage* page;
	std::string path;
};

#endif