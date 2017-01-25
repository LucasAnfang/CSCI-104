#include "stackint.h"
#include <iostream>

using namespace std;

int main()
{
   StackInt stack;
   stack.push(1);
   stack.push(2001);
   stack.push(654);
   
   while(!stack.empty())
   {
   cout << "Top: " << stack.top() << endl;
   stack.pop();
   }
   return 0;
}
