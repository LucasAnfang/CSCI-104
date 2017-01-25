#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

    bool isValid(map<char,int>color_map, map<char,string>adj_map, char curr);
    bool color_c( map<char,string>adj_map, int cur, vector<char> countries);
        map<char,string> adj_map;
    map<char,int>color_map;
    vector<char> countries;
int main (int argc, char * argv[])
{


    int max_rows = 80;
    int max_cols = 80;
    char container[max_rows][max_cols];
    for(int a = 0; a<max_rows; a++)
    {
        for(int b = 0; b<max_cols; b++)
        {
            container[a][b]=' ';
        }
    }
    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail())
    {
        return 1;
    }
    int number_of_countries;
    int num_rows;
    int num_cols;

    inFile>>ws>>number_of_countries>>ws>>num_rows>>ws>>num_cols>>ws;
    //cout << number_of_countries << endl;
    //cout << num_rows << endl;
   // cout << num_cols << endl;

    for(int a = 0; a<num_rows; a++)
    {
        for(int b = 0; b<num_cols; b++)
        {
            if(container[a][b]==' ')
            {
                char ch;
                inFile>>ch;
                container[a][b] = ch;
            }
        }
    }
    // for(int a = 0; a<num_rows; a++)
    // {
    //     for(int b = 0; b<num_cols; b++)
    //     {
    //         //cout << container[a][b];
    //     }
    //    // cout <<endl;
    // }
    // // map<char,string> adj_map;
    // map<char,int>color_map;
    // vector<char> countries;

    for(int a = 0; a<num_rows; a++)
    {
        for(int b = 0; b<num_cols; b++)
        {
            char up = container[a-1][b];
            char right = container[a][b+1];
            char down = container[a+1][b];
            char left = container[a][b-1];
            if(a == 0)
            {
                up = ' ';
            }
            if(b == 0)
            {
                left = ' ';
            }
            map<char,string>::iterator it =adj_map.find(container[a][b]);
            if(it!=adj_map.end()) //in map
            {
                if(adj_map[container[a][b]].find(up)!=string::npos) {}
                else if(up!= ' '&&up!=container[a][b])
                {
                    adj_map[container[a][b]]+=up;
                }
                if(adj_map[container[a][b]].find(right)!=string::npos) {}
                else if(right!=' '&&right!=container[a][b])
                {
                    adj_map[container[a][b]]+=right;
                }
                if(adj_map[container[a][b]].find(down)!=string::npos) {}
                else if(down!= ' '&&down!=container[a][b])
                {
                    adj_map[container[a][b]]+=down;
                }
                if(adj_map[container[a][b]].find(left)!=string::npos) {}
                else if(left!= ' ' && left!=container[a][b])
                {
                    adj_map[container[a][b]]+=left;
                }
            }
            else //not in map yet
            {
                adj_map[container[a][b]]="";
               // cout << "Just added " << container[a][b] << " to the map" << endl;
            }
            map<char,int>::iterator it1 =color_map.find(container[a][b]);
            if(it1!=color_map.end()) {} //in the map
            else
            {
                color_map[container[a][b]]=0;
                countries.push_back(container[a][b]);
            }
        }
    }
    // for(map<char,string>::iterator it1 = adj_map.begin(); it1!= adj_map.end(); ++it1)
    // {
    //     cout << it1->first << " " << it1->second << endl;
    // }
    // for(map<char,int>::iterator it1 = color_map.begin(); it1!= color_map.end(); ++it1)
    // {
    //     cout << it1->first << " " << it1->second << endl;
    // }
    // for(vector<char>::iterator it1 = countries.begin(); it1!= countries.end(); ++it1)
    // {
    //     cout << (*it1) << endl;
    // }
    //
     color_c(adj_map,0,countries);
   //  if(color_c(color_map,adj_map,0,countries))
   // {
   //      //color_c(color_map,adj_map,0,countries)
        for(map<char,int>::iterator it1 = color_map.begin(); it1!= color_map.end(); ++it1)
        {
            cout << it1->first << " " << it1->second << endl;
        }
   //  }
   //  else
   // {
   //      cout << "BEEP BOOP, INVALID COLORING. TERMINATE... TERMINATE..." <<endl;
   //  }
}
bool isValid(map<char,int>color_map, map<char,string>adj_map, char curr)
{
    for(int position = 0; position < adj_map[curr].length(); position++)
    {
       char temp = adj_map[curr].at(position);
       if(color_map[temp]==color_map[curr])
       {
            return false;
       } 
       else continue;
    }
    return true;


}

bool color_c(map<char,string>adj_map, int cur, vector<char> countries)
{
     char curr = countries[cur];
    if(cur == color_map.size())
    {
        return true;
    }
    for(int color = 1; color <= 4 ; color++ )
    {
        color_map[curr]=color;
        if(isValid(color_map,adj_map,curr))
        {
            //cout << curr << ' ' << color_map[curr] << endl;
                if(color_c(adj_map,cur+1,countries)) 
                {
                    return true;
                }
        }
        color_map[curr]=0;
    }
    return false;
}