#include "stackint.h"
#include "alistint.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <map>


using namespace std;
bool breaker = false;
void parse_vars(string &line, map<int,int> &context);
bool epression_part_calc(bool first_truth, bool second_truth, bool and_form, bool or_form);
bool expression_calc(StackInt &stack);
//Consts
const int OPEN_PAREN=-1;
const int AND = -2;
const int OR = -3;
const int TILDA = -4;

int main (int argc, char * argv[])
{
    map <int, int> context;
    string line;
    ifstream in_file;
    in_file.open(argv[2]);
    if(in_file.is_open())
    {
        while(getline(in_file, line))
        {
            parse_vars(line, context); // the parse file
        }
    } else cout << "Unable to open second file" << endl;




    in_file.close();
    string str;
    ifstream infile;
    infile.open(argv[1]);
    if(infile.is_open())
    {
        while(getline(infile, line))
        {
            StackInt stack;
            bool breaker = false;
            for(unsigned int i=0; i<line.length(); i++)
            {
                if(line[i]==' '&&breaker == false)
                {
                    continue;
                }
                else if(line[i] == ')'&&breaker == false)
                {
                    bool total;

                    total = expression_calc(stack);
                    cout << "Part of the truth value only in the current parenthese" << total << endl;
                    if(total)
                    {
                        stack.push(-10);
                    }
                    else
                    {
                        stack.push(-20);
                    }
                }
                else if(line[i] == '('&&breaker == false)
                {
                    stack.push(OPEN_PAREN);
                }
                else if(line[i] == '&'&&breaker == false)
                {
                    stack.push(AND);
                }
                else if(line[i] == '|'&&breaker == false)
                {
                    stack.push(OR);
                }
                else if(line[i] == '~'&&breaker == false)
                {
                    stack.push(TILDA);
                }
                else if(isdigit(line[i])&&breaker == false)
                {
                    string temp = "";
                    int temp_num;
                    while(isdigit(line[i]))
                    {
                        temp+=line[i];
                        i++;
                    }
                    i--;
                    temp_num = atoi(temp.c_str());

                    map <int,int>::iterator it;

                    if(it != context.end())
                    {
                        it = context.find(temp_num);
                        if(it->second == -10)
                        {
                            stack.push(-10);
                            cout << temp_num<< "'s truth value: " << stack.top() << endl;
                        }
                        else if(it->second == -20)
                        {
                            stack.push(-20);
                            cout <<temp_num << "'s truth value: " << stack.top() << endl;
                        }
                        else
                        {
                            cout << "Unknown variable" << endl; //add a malformed type
                        }
                    }

                } else breaker = true;

            }
        }
    } else cout << "Unable to open first file" << endl;
}

void parse_vars(string &line, map<int,int> &context)
{
    istringstream lineStream(line);
    lineStream >> ws;
    int variable_number;
    if(lineStream >> variable_number)
    {
    } else cout << "The variable number was not an integer!" << endl;
    lineStream >> ws;
    char truth_value;
    if(lineStream >> truth_value)
    {
        if(truth_value == 'T')
        {
            context[variable_number] = -10;
        } else if (truth_value == 'F') {
            context[variable_number] = -20;
        } else cout << "Faulty truth value for in the input file!" << endl;
    } else cout << "Faulty truth value for in the input file!" << endl;
}

bool expression_calc(StackInt &stack)
{
    int first_truth_val;
    int second_truth_val;
    bool first_loaded = false;
    bool second_loaded = false;
    bool and_form = false;
    bool or_form = false;
    bool output = false;
    bool first_truth = false;
    bool second_truth = false;
    while(stack.top() != -1)
    {
      //cout << stack.top() << endl;
        int tilda_count = 0;
        if((stack.top())%1 == 0 && first_loaded == false)
        {
            first_truth_val = stack.top();
            
            if(first_truth_val == -10) //T to F
            {
                first_truth = true;
            }
            else if (first_truth_val == -20) //F to T
            {
                first_truth = false;
            }
            stack.pop();

            while(stack.top() == TILDA)
            {
                tilda_count++;
                stack.pop();

            }

            if((tilda_count+2)%2 == 1) //odd num of tilda's
            {
                if(first_truth) //T to F
                {

                    first_truth = false;
                }
                else //F to T
                {

                    first_truth = false;
                }
            }

            tilda_count = 0;
            first_loaded = true;
        }
        else if(first_loaded == true && stack.top() == AND)
        {
            and_form = true;
            stack.pop();
        }
        else if(first_loaded == true && stack.top() == OR)
        {
            or_form = true;
            stack.pop();
        }
        else if((stack.top())%1 == 0 && first_loaded == true)
        {
            second_truth_val = stack.top();
            if(second_truth_val == -10) //T to F
            {
                second_truth = true;
            }
            else if (second_truth_val == -20) //F to T
            {
                second_truth = false;
            }

            stack.pop();
            while(stack.top() == TILDA)
            {
                stack.pop();
                tilda_count++;
            }
            if((tilda_count+2)%2 == 1) //odd num of tilda's
            {
                if(second_truth) //T to F
                {
                    second_truth = false;
                }
                else //F to T
                {
                    second_truth = true;
                }
            }
            tilda_count = 0;
            second_loaded = true;
        }
        else if(first_loaded == true && second_loaded == true)
        {
            first_truth = epression_part_calc(first_truth, second_truth, and_form, or_form);
        } else cout << "MALFORMED" << endl;
        first_loaded = true;
        output = first_truth;
    }
    return output;
}

bool epression_part_calc(bool first_truth, bool second_truth, bool and_form, bool or_form)
{

    if(and_form)
    {
        if(first_truth == true && second_truth == true)
        {
            first_truth = true;
        }
        else first_truth = false;
    }
    if(or_form)
    {
        if(first_truth == true || second_truth == true)
        {
            first_truth = true;
        }
        else first_truth = false;
    }
    if(or_form == false && and_form == false)
    {
        cout << "MALFORMED" << endl;
    }
    return first_truth;
}

