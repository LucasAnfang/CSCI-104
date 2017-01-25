#include <string>
#include <list>
using namespace std;

// Pre-emptive declarations
template <class T, class Comparator>
void mergeSort(T a[], int p, int r, Comparator &comp);

template <class T, class Comparator>
void merge(T a[], int p, int q, int r, Comparator &comp);

// This is the main driver
template <class T, class Comparator>
void mergeSort (list<T> &myArray, Comparator &comp)
{
	int arraylength = myArray.size();
	T* a = new T[arraylength];
	int index = 0;
	for(typename list<T>::iterator it = myArray.begin(); it != myArray.end(); ++it)
	{
		a[index++] = (*it);
	}
	mergeSort(a, 0, arraylength-1, comp);
	myArray.clear();
	for( int i = 0; i < arraylength ; i++)
	{
		myArray.push_back(a[i]);
	}
	delete[] a;
}

// This is the main recursive sorting routine.  It parcels the
// array into pieces, then re-merges them.
template <class T, class Comparator>
void mergeSort (T a[], int p, int r, Comparator &comp)
{
	//check if there is anything to sort
	if(r > p)
	{
		int q = (p + r)/2;
		mergeSort(a, p, q, comp);
		mergeSort(a, q+1, r, comp);
		merge(a, p, q, r, comp);
	}
}

// This routine merges stacks of values back together.
template <class T, class Comparator>
void merge(T a[], int p, int q, int r, Comparator &comp)
{
	if(p == r) //There is only one element
	{
		return;
	}
	else if(r == p+1) // there are two elements
	{
		//check if we need to swap them
		if(comp(a[r], a[p]))
		{
			T temp = a[p];
			a[p] = a[r];
			a[r] = temp; 
		}
	}
	else
	{
		//there are two stacks to merge
		int lTop = p;
		int rTop = q+1;
		int sLength = r -p +1; // this is the number of things to merge
		int sTop = 0;
		T* s = new T[sLength];

		while(sTop < sLength)
		{
			//see if both stacks still have things in them
			if(lTop <= q && rTop <= r)
			{
				if(comp(a[lTop], a[rTop])) // the lesser one is on the left
				{
					s[sTop++] = a[lTop++];
				}
				else
				{
					s[sTop++] = a[rTop++];
				}
			}
			else 
			{
				//one stack is empty 
				if(lTop <= q)
				{
					//right stack is empty
					s[sTop++] = a[lTop++];
				}
				else 
				{
					//left stack is empty
					s[sTop++] = a[rTop++];
				}
			}
		}
		//copy the results back
		for(int i = 0; i < sLength ; i++)
		{
			a[p+i] = s[i];
		}
		delete[] s;
	}
}

