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
std::map<std::string, std::string> parseConfiguration(std::string configuration_filename);

int main(int argc, char* argv[])
{

    string configuration_filename;
    if(argc < 2) {
        //cerr << "usage: ./search index_file...Please provide an index file" << endl;
        //User did not specify configuration
        configuration_filename = "config.txt";
    }
    else
    {

        configuration_filename = argv[1];
    }
    //cout << "parsing configuration file " << endl;
    map<string, string> configurationParameters = parseConfiguration(configuration_filename);
    //string output_filename = configurationParameters["OUTPUT_FILE"];
    string seed_filename = configurationParameters["INDEX_FILE"];
    string string_restart_probability = configurationParameters["RESTART_PROBABILITY"];
     double epsilon = atof(string_restart_probability.c_str());
    string string_step_number = configurationParameters["STEP_NUMBER"];
         int step_number = atoi(string_step_number.c_str());
        // cout << "Step number: " << step_number << " epsilon: " << epsilon << endl;
    //cout << "done parseing configuration file" << endl;
    //string index_filename;
    //index_filename = argv[1];
    QApplication app(argc, argv);
    Form form(seed_filename, step_number, epsilon);
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
    for(set<WebPage*>::iterator it = results.begin(); it != results.end(); ++it)
    {
        cout << (*it)->filename() << endl;
        cout << "+---+" << endl;
        cout << (**it) << "\n" << endl;
        i++;
    }
}

std::map<std::string, std::string> parseConfiguration(std::string configuration_filename)
{
    //cout << "testing" << endl; 
    ifstream inFile;

    map<string, string> configurationParameters;
    inFile.open(configuration_filename.c_str());

    //stringstream iss;
    //iss << inFile.rdbuf();
    string line;
    bool stop = false;
    while(getline(inFile, line))
    {
        //cout << "new line" << endl;
        stringstream iss(line);
        iss>>ws;
        char ch;
        string parameter;
        string value;
        while(iss.get(ch))
        {
          stop = false;
            if(ch == ' ')
            {
                iss.get(ch);
                while(ch == ' ')
                {
                    if(iss.get(ch)) continue;
                    else break;
                }
                continue;
            }
            else if(ch == '#')
            {
                //cout << "testing comments" << endl;
                break;
            }
           // else 
           // {
              //cout << "ch: " << "|"<< ch<< "|"<< endl;
                while(ch!= ' '&& ch!='=')
                {
                    parameter+=ch;
                                 // cout << "ch: " << "|"<< ch<< "|"<< endl;
                    iss.get(ch);
                   // break;
                }

                iss.get(ch);
                if(ch == ' ')
                {
                    iss.get(ch);
                    while(ch == ' ') //keeps reading over the extra spaces but doesnt put them to the ofstream
                    {
                        if(iss.get(ch)) continue;
                        else break; //happens at the end of the document
                    }
                }
                if(ch == '=')
                {
                 // cout << "equals hit" << endl;
                  iss.get(ch);
                }
                //cout << "parameter: "<<"|" <<parameter <<"|"<< endl;

                if(ch == ' ')
                {
                    iss.get(ch);
                    while(ch == ' ') //keeps reading over the extra spaces but doesnt put them to the ofstream
                    {
                        if(iss.get(ch)) continue;
                        else break; //happens at the end of the document
                    }
                }
                //cout << ch << endl;
                //break;
                if(ch == '.')
                {
                  iss.get(ch);
                 // cout << "period hit" << endl;
                  //break;
                  if(ch == '/')
                  {
                    //cout << "slash hit" << endl;
                    iss.get(ch);
                    if(ch == ' ')
                    {
                        iss.get(ch);
                        while(ch == ' ') //keeps reading over the extra spaces but doesnt put them to the ofstream
                        {
                            if(iss.get(ch)) continue;
                            else break; //happens at the end of the document
                        }
                    } 
                    
                    while(ch!= ' '&& ch!= '#')
                    {
                      //cout << "hi" << endl;
                        value+=ch;
                                      //cout << "ch: " << "|"<< ch<< "|  ";
                        if(iss.get(ch)) continue;
                        else break;
                        //break;
                    } 

                    //cout << endl;
                  //cout << "value: "<<"|" <<value <<"|"<< endl;
                  configurationParameters[parameter]= value;
                  value="";
                  parameter=""; 
                  stop = true;
                  //break;

//cout << "value: "<<"|" <<value <<"|"<< endl;
                  }
 
                }
                else
                {
                  while(ch!= ' ' && ch!= '#')
                  {
                      value+=ch;
                                    //cout << "|"<< ch<< "| ";
                      if(iss.get(ch))
                      {
                        continue;
                      }
                      else break; 

                     // break;
                  }
                  //cout << endl;
                  //cout << "value: "<<"|" <<value <<"|"<< endl; 
                  configurationParameters[parameter]= value;
                  value="";
                  parameter="";   
                  stop = true;
                }
            //}
            //break;
            if(stop == true )
            {
              break;
            }
        }

    }

    // for( map<string, string >::iterator it1 = configurationParameters.begin(); it1!= configurationParameters.end(); ++it1)
    // {
    //     cout << (*it1).first << " " << (*it1).second << endl;
    // }
    return configurationParameters;

}