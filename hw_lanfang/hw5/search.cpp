#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream> 
#include <cctype>
#include <sstream>
#include <locale>

#include "webpage.h"
#include "searcheng.h"
#include "mdparser.h"
#include "util.h"
#include "form.h"
#include <QApplication>

using namespace std;

void display_results(set<WebPage*>& results);

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "usage: ./search index_file...Please provide an index file" << endl;
    return 1;
  }
  string index_filename;
  index_filename = argv[1];
  QApplication app(argc, argv);
  Form form(index_filename);
  form.show();
  return app.exec();
  return 0;
}

void display_results(set<WebPage*>& results)
{
  int hits = results.size();
  cout << hits << " hits." << endl;
  cout << "=====" << endl;
  int i=0;
  for(set<WebPage*>::iterator it = results.begin();it != results.end();++it)
  {
    cout << (*it)->filename() << endl;
    cout << "+---+" << endl;
    cout << (**it) << "\n" << endl;
    i++;
  }  
}
