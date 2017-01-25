#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include "hashtable.h"
#include "minheap.h"
#include <set>
#include <deque>

using namespace std;

vector<string> find_neighbors(string a);
int compute_h(string a);

set<string> fileWords;
vector<string>neighbors;
string from_word;
string to_word;
HashTable Closed_List;
HashTable Depths;
map<string, string> child_to_parent;

MinHeap Open_List(10);

int main (int argc, char * argv[])
{
    if(argc < 4) {
        cerr << "You do not have all three command line parameters entered" << endl;
        return 1;
    }
    from_word = argv[1];
    to_word = argv[2];
    int from_word_size = from_word.length();
    int to_word_size = to_word.length();
    if(from_word_size!=to_word_size)
    {
        cerr << "The two words have different lengths... no possible path" << endl;
        return 1;
    }

    ifstream in_file;
    in_file.open(argv[3]);

    int numWords = 0;
    if(in_file.is_open())
    {
        bool first_loaded = false;
        string word = "";
        string line = "";
        while(getline(in_file, line))
        {
            istringstream iss(line);
            if(!first_loaded)
            {
                if(iss>>numWords)
                {
                    first_loaded = true;
                }
            }
            else
            {
                if(iss>>word)
                {
                    std::transform(word.begin(),word.end(), word.begin(), ::tolower);
                    if(word.length() == from_word_size)
                    {
                        fileWords.insert(word);
                    }
                }
            }
        }
    }
    // cout << "Number of words: " << numWords << endl;
    // for(set<string>::iterator it = fileWords.begin();it!=fileWords.end();++it)
    // {
    // 	cout << "|" << (*it) << "|" << " ";
    // }
    // cout << endl;

    const char* to_word_char = to_word.c_str();
    const char* from_word_char = from_word.c_str();
    vector<string> Who_cares = find_neighbors(from_word);

    //cout << "Neighbors: ";
    // for(vector<string>::iterator it = neighbors.begin();it!=neighbors.end();++it)
    // {
    // 	cout << (*it) << " ";
    // }
    //cout << endl;
    int order = 0;
    Open_List.add(from_word, 0);
    int depth = 0;
    Depths.add(make_pair(from_word,depth));
    int expansions = 0;

    while(!Open_List.isEmpty())
    {

        string current_parent = Open_List.peek();
        Open_List.remove();
        try {
            Closed_List.add(make_pair(current_parent,order));
           // expansions++;
        }
        catch(const char* str)
        {
            //expansions--;
            //cout <<"shitsky" << endl;
            continue;
        }

        //cout << current_parent << " ";
        if(current_parent == to_word)
        {
            // cout << endl;
            // cout << "Expansions: " << expansions << endl;
           // expansions--;
            break;
        }
        expansions++;
        //expansions++;
        // int testing = Closed_List.find(current_parent);
        // cout << "testing this mofo : " << testing << endl;

        neighbors = find_neighbors(current_parent);
        for(vector<string>::iterator it = neighbors.begin(); it!=neighbors.end(); ++it)
        {

            int parent_g = Depths.find(current_parent);
            //cout << current_parent << " depth: " << parent_g;
            try {
                Depths.add(make_pair((*it),parent_g+1));
            }
            catch(const char* str)
            {
                //cout <<"shitsky" << endl;
            }
            int child_g = Depths.find((*it));
            //cout << " " << (*it) << " depth: " << child_g;
            int h_val = compute_h((*it));
            int f_val = child_g + h_val;
            int priority = f_val*((*it).size()+1)+h_val;
            //cout << " " << (*it) << " f value: " << f_val << endl;
            //Open_List.add((*it),priority);
            try {
                const int result = Closed_List.find((*it));
                //cout << "result for " << (*it) << " is " << result << endl;
            }
            catch(const char* str)
            {

                //cout <<"caught exception finding " << (*it) << " " << str<< endl;
                //Open_List.add((*it),priority);
                try {
                    //cout << "what the fuuck" << endl;
                    Open_List.add((*it),priority);
                    child_to_parent[(*it)] = current_parent;
                    //expansions++;
                    //cout << 1 << endl;
                }
                catch(const char* str) {
                    //cout << "what" << endl;
                    Open_List.update((*it),priority);

                    //child_to_parent[(*it)] = current_parent;
                    //expansions++;
                    //cout << current_parent << endl;
                }
            }
        }
    }
    if(child_to_parent.count(to_word)==0)
    {
        cout << "NO PATH FOUND... TERMINATE ... TERMINATE" << endl;
        return 1;
    }
    string parent_word = "";
    string current_word = to_word;
    deque<string> output;
    while(parent_word!=from_word)
    {
        parent_word = child_to_parent[current_word];
        //cout  << current_word<< " ";
        output.push_front(current_word);
        current_word= parent_word;
        //	break;
    }
    output.push_front(from_word);
    for(deque<string>::iterator it = output.begin(); it!=output.end(); ++it)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << "Expansions: "<<expansions<< endl;
    //cout << child_to_parent["tail"] << endl;

    return 0;
}

vector<string> find_neighbors(string a)
{
    neighbors.clear();
    for(set<string>::iterator it = fileWords.begin(); it!=fileWords.end(); ++it)
    {
        int numberOfDifferences = 0;
        //cout << "Parent word: " << a << " Child Word: " << (*it);
        const char* neighbor_char = (*it).c_str();
        const char* a_char = a.c_str();
        for( int i = 0; i < a.length(); i++ )
        {
            if( a_char[i] != neighbor_char[i] )
            {
                numberOfDifferences++;
            }
        }
        if(numberOfDifferences == 1)
        {
            neighbors.push_back((*it));
        }

        int h_val = compute_h(*it);
        //cout << " Difference: " << numberOfDifferences << " H value: " << h_val <<endl;

    }
    return neighbors;
}

int compute_h(string a)
{
    int numberOfDifferences = 0;
    //cout << " current word: " << a << " End Word: " << to_word;
    const char* end_char = to_word.c_str();
    const char* a_char = a.c_str();
    for( int i = 0; i < a.length(); i++ )
    {
        if( a_char[i] != end_char[i] )
        {
            numberOfDifferences++;
        }
    }
    return numberOfDifferences;
}