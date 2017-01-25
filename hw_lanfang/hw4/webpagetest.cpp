#include "webpage.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string filename1 = "data/data1.txt";
	string filename2 = "data/data2.txt";

	WebPage webpage1(filename1);
	cout << webpage1 << endl;
	MySetString webpage1_words = webpage1.all_words();
	MySetString webpage1_links = webpage1.get_links();
	WebPage webpage2(filename2);
	webpage2.add_outgoing_link(&webpage1);
	webpage1.add_incoming_link(&webpage2);
	MySetString webpage2_words = webpage1.all_words();
	MySetString webpage2_links = webpage1.get_links();

	cout << "All words from webpage 1: " << endl;
	for(set<string>::iterator it3 = webpage1_words.begin(); it3!= webpage1_words.end(); ++it3)
	{
		cout << *it3 << endl;
	}
	cout << endl;
	cout << "All links frome webpage 1: " << endl;
	for(set<string>::iterator it3 = webpage1_links.begin(); it3!= webpage1_links.end(); ++it3)
	{
		cout << *it3 << endl;
	}

	MySetWebPage webpage1_incoming_links = webpage1.incoming_links();
	MySetWebPage webpage2_outgoing_links = webpage2.outgoing_links();
	cout << "All webpage1_incoming_links: " << endl;
	for(set<WebPage*>::iterator it3 = webpage1_incoming_links.begin(); it3!= webpage1_incoming_links.end(); ++it3)
	{
		cout << **it3 << endl;
	}
	cout << "All webpage2_outgoing_links: " << endl;
	for(set<WebPage*>::iterator it3 = webpage2_outgoing_links.begin(); it3!= webpage2_outgoing_links.end(); ++it3)
	{
		cout << **it3 << endl;
	}



}