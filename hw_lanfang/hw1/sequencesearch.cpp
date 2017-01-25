#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char * argv[])
{
ifstream inFile(argv[1]); //takes in the text file through the arguement line
stringstream iss;
iss << inFile.rdbuf();
string temp; //temporary holder for the rows input from the file
iss >> temp;
cout << temp << endl;
int rows = atoi(temp.c_str()); //switches the variable type from string to integers
// takes number of colums in rows 
int *array = new int[rows];
// takes the value in the rows
double **array2 = new double*[rows];

//fills the variable length array with the info from the document
for(int i = 0; i < rows; i++) 
{
	iss >> temp;
	array[i] = atoi(temp.c_str());
	array2[i] = new double[atoi(temp.c_str())];
}
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < array[i]; j++)
	{
		iss >> temp;
		array2[i][j]= atof(temp.c_str()); //atof because it needs to be a float for the decimals 
	}
}	

int max = 0;

for (int i = 0; i < rows; i++) //this part of the code starts at the left side and searches right
{	
	for (int j = 0; j < array[i]; j++)
	{
		int max_temp = 1;
		double prev_number = array2[i][j]; //resets the prev number or sets it at the beginning
		for(int b = j; b < array[i]; b++)
		{
			if(prev_number < array2[i][b+1])
			{
				max_temp++; // max temp is an easy way to save the max each time and compare it to the actual maximum when the iteration is completed
			}
			else break;
			prev_number = array2[i][b+1];
		}
		if(max_temp > max)
		{
			max = max_temp;
		}
	}
}


for (int i = 0; i < rows; i++) //this starts on the right side and searches left in each of the rows for the max_temp and if the max_temp in this search is higher that the previous max it resents the max variable
{
	for (int j = array[i]; j > 0; j--)
	{ 
	//starts at the top and checks down each column for the longest increasing chain. 
		int max_temp = 1;
		double prev_number = array2[i][j];
		for(int b = j; b > 0; b--)
		{
			if(prev_number < array2[i][b-1])
			{
				max_temp++;
			}
			else break;
			prev_number = array2[i][b-1];
		}
		if(max_temp > max)
		{
			max = max_temp;
		}
	}
}


for (int i = 0; i < rows; i++) // going Down
{ //starts at the top and checks down each column for the longest increasing chain. 
	for (int j = 0; j < array[i]; j++)
	{
		int max_temp = 1;
		double prev_number = array2[i][j];
		for(int b = i; j < array[i+1]; b++)
		{
			if(b+1 > rows-1)
			{
				break;
			}
			if(prev_number < array2[b+1][j])
			{
				max_temp++;
	
				prev_number = array2[b+1][j];
			}
			else break;			
		}
		if(max_temp > max)
		{
			max = max_temp;
		}
	}
}

for (int i = 0; i < rows; i++) // going up but really just doing it down but checking decreasing
//same as the previous procedure except for flip in sign in the comparison here: prev_number > array2[b+1][j]
{
	for (int j = 0; j < array[i]; j++)
	{
		int max_temp = 1;
		double prev_number = array2[i][j];
		for(int b = i; j < array[i+1]; b++)
		{
			if(b+1 > rows-1)
			{
				break;
			}
			if(prev_number > array2[b+1][j])
			{
				max_temp++;
				prev_number = array2[b+1][j];
			}
			else 
			{
				break;
			}
			
		}
		if(max_temp > max)
		{
			max = max_temp;
		}
	}
}

ofstream outfile;
outfile.open(argv[2]); //puts the result to the outfile.txt
outfile << max << endl;
outfile.close();

// when done
delete[] array; //memory deallocation
for (int i = 0; i < rows; i++)
{
	delete[] array2[i];
}
delete[] array2;
inFile.close(); //close the file

}
