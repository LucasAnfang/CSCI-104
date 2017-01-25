#include "myset.h"
#include "webpage.h"
#include <string>

MySetString::MySetString() : std::set<std::string>() {}

MySetString MySetString::set_intersection(const MySetString& other) {
	MySetString temp;
	for(set<string>::iterator it1 = this->begin(); it1!= this->end(); ++it1)
	{
		for(set<string>::iterator it2 = other.begin(); it2!= other.end(); ++it2)
		{
			if((*it1).compare(*it2) == 0)
			{
				temp.insert((*it1));
				break;
			} 
		}
	}
	return temp;
}

MySetString MySetString::set_union(const MySetString& other) {
	MySetString temp;
	for(set<string>::iterator it1 = this->begin(); it1!= this->end(); ++it1)
	{
		temp.insert((*it1));
	}
	for(set<string>::iterator it2 = other.begin(); it2!= other.end(); ++it2)
	{
		temp.insert((*it2));
	}	

	return temp;

}
MySetWebPage::MySetWebPage() : std::set<WebPage*>() {}

MySetWebPage MySetWebPage::set_intersection(const MySetWebPage& other) {
	MySetWebPage temp;
	for(set<WebPage*>::iterator it1 = this->begin(); it1!= this->end(); ++it1)
	{
		for(set<WebPage*>::iterator it2 = other.begin(); it2!= other.end(); ++it2)
		{
			if((*it1)==(*it2))
			{
				temp.insert((*it1));
				break;
			} 
		}
	}
	return temp;
}

MySetWebPage MySetWebPage::set_union(const MySetWebPage& other) {
	MySetWebPage temp;
	for(set<WebPage*>::iterator it1 = this->begin(); it1!= this->end(); ++it1)
	{
		temp.insert((*it1));
	}
	for(set<WebPage*>::iterator it2 = other.begin(); it2!= other.end(); ++it2)
	{
		temp.insert((*it2));
	}	

	return temp;

}
