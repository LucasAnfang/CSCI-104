#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
 

using namespace std;

void makePalindromes(ostream& ofile, char* options, int size);
void makePalindromeHelper(ostream& ofile, char* options, int len, int size, string pal);

int main(int argc, char* argv[])
{
  if(argc < 4){
    cerr << "Please provide an output file, a string of characters, and the max length" << endl;
    return 1;
  }

  ofstream ofile(argv[1]);
  int len = atoi(argv[3]);
  makePalindromes(ofile, argv[2], len);
  ofile.close();
  return 0;
}
void makePalindromes(ostream& ofile, char* options, int size)
{
ofile << "\0";
ofile << endl;
 for(int i = 0; i < size; i++)
    {
         string hold;
         hold = options[i];
      makePalindromeHelper( ofile, options, 1, size, hold);
    } 

}

void makePalindromeHelper(ostream& ofile, char* options, int len, int size, string pal)
{
   if(len < size)
   {  
      if((len+2)%2 == 0)
      {
         for(int i = 0; i < size; i++)
         {
         string temp = pal;
         string hold;
         hold = options[i];
         temp.insert((len/2),hold);
         makePalindromeHelper(ofile, options, len+1, size, temp);
         }
      }
      else
      {
         string temp = pal;
         string hold;
         hold = pal[((len+1)/2)-1];
         temp.insert(((len+1)/2),hold);
         makePalindromeHelper(ofile, options, len+1, size, temp);
      } 
      ofile << pal; 
      ofile << endl;      
   }    
}
