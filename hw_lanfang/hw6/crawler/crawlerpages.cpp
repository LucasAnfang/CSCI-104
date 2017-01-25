#include "crawlerpages.h"


	CrawlerPages::CrawlerPages(WebPage* page, string path) : 
	page(page),path(path)
	{

	}
	CrawlerPages::~CrawlerPages()
	{

	}
	WebPage* CrawlerPages::getPage()
	{
		return page;
	}

	std::string CrawlerPages::getPath()
	{
		return path;
	}