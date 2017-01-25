#include "myset.h"
#include <iostream>

using namespace std;

int main()
{
	MySetString words1;
	words1.insert("the");
	words1.insert("book");
	words1.insert("seat");
	words1.insert("pops");
	words1.insert("death");
	words1.insert("of");
	words1.insert("me");

	MySetString words2;
	words2.insert("the");
	words2.insert("coffee");
	words2.insert("where");
	words2.insert("booger");
	words2.insert("death");
	words2.insert("of");
	words2.insert("not");
	words2.insert("me");
	words2.insert("death");

	MySetString test1;
	MySetString test2;



	cout << "String intersection: " << endl;
	test1 = words1.set_intersection(words2);
	for(set<string>::iterator it3 = test1.begin(); it3!= test1.end(); ++it3)
	{
		cout << *it3 << endl;
	}
	cout << "String union: " << endl;
	test1 = words1.set_union(words2);
	for(set<string>::iterator it4 = test1.begin(); it4!= test1.end(); ++it4)
	{
		cout << *it4 << endl;
	}






}



