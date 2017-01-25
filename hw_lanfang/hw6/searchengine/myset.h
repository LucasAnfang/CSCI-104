#ifndef MYSET_H
#define MYSET_H
#include <set>
#include <string>
using namespace std;

template<class T>
class MySet : public std::set<T>
{
public:
  MySet() : std::set<T>() {};
  MySet set_intersection(const MySet& other){
	MySet<T> temp;
	for(typename set<T>::iterator it1 = this->begin(); it1!= this->end(); ++it1)
	{
		for(typename set<T>::iterator it2 = other.begin(); it2!= other.end(); ++it2)
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
  MySet set_union(const MySet& other)
  {
  		MySet<T> temp;
	for(typename set<T>::iterator it1 = this->begin(); it1!= this->end(); ++it1)
	{
		temp.insert((*it1));
	}
	for(typename set<T>::iterator it2 = other.begin(); it2!= other.end(); ++it2)
	{
		temp.insert((*it2));
	}	

	return temp;

  }
};

#endif