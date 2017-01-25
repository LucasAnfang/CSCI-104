#include "minheap.h"
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;


MinHeap::MinHeap (int d) : d(d)
{

}

MinHeap::~MinHeap ()
{
}

void MinHeap::heapify(int index)
{
  int left = d*index+1; // check if this is a leaf node
  if(left>= heapArray.size()) return; 
  //const string indexString = heapArray[index]->getString();
  int smallest = index;
  for(int i = 1; i <= d; i++)
  {
    int child_index = d*index+i;
    if(child_index< heapArray.size())
    {
      if(heapArray[child_index]->getPriority() < heapArray[index]->getPriority())
      {
	smallest = child_index;
      }
    }
    else break;
  }
  //cout << "smallest = " << smallest << endl;
  if(smallest != index)
  {
    MapNode* temp = heapArray[index];
    const string indexString = temp->getString();
    const string smallestString = heapArray[smallest]->getString();
    heapArray[index] = heapArray[smallest];
    heapArray[smallest] = temp;
    
    string_map.update(std::make_pair<string, int> (indexString, smallest));
    string_map.update(std::make_pair<string, int> (smallestString, index));
    heapify(smallest);
  } 
}

void MinHeap::decreaseKey( int index, int priority )
{
  heapArray[ index ]->setPriority( priority );
  int loc = index;
  int parent = ( loc - 1 ) / d;
  while( loc > 0 && heapArray[ parent ]->getPriority() > heapArray[ loc ]->getPriority() )
  {
    // Child has lower priority than its parent.  Swap them.
    MapNode* temp = heapArray[parent];
    const string parentString = temp->getString();
    const string item         = heapArray[loc]->getString();
    heapArray[parent] = heapArray[loc];
    heapArray[loc] = temp;
    
    string_map.update(std::make_pair<string, int> (parentString, loc));
    string_map.update(std::make_pair<string, int> (item, parent));
    loc = parent; 
    parent = (loc - 1)/d;
  }
}

void MinHeap::add (std::string item, int priority)
{//cout << "NOOOOOOOOOO NO GOD NO" << endl;
//new
// for(vector<MapNode*>::iterator it = heapArray.begin(); it!=heapArray.end();++it)
// {
	
// 	throw "already in the heap";
// }
//new
  MapNode* newNode = new MapNode(item, priority);
  heapArray.push_back(newNode);
  int loc = heapArray.size() - 1;
  
  string_map.add(std::make_pair<string, int> (item, loc));
  int parent = (loc-1)/d;
  //cout << "parent = " <<parent << " loc = " << loc<< endl;
  
  
  while(parent>=0 && heapArray[loc]->getPriority()<heapArray[parent]->getPriority())
  {
    MapNode* temp = heapArray[parent];
    const string parentString = temp->getString();
    heapArray[parent] = heapArray[loc];
    heapArray[loc] = temp;
    
    string_map.update(std::make_pair<string, int> (parentString, loc));
    string_map.update(std::make_pair<string, int> (item, parent));
    loc = parent; 
    parent = (loc - 1)/d;
  }
  string_fix(parent);
  
}

const std::string & MinHeap::peek () const
{
  if(heapArray.empty())
  {
    throw "Peek: heap is empty";
  }
  return heapArray[0]->getString(); 
}

void MinHeap::remove()
{
  //cout << "Removing top of heap: size before is " << heapArray.size() << endl;
  if( heapArray.size() == 0 )
  {
    throw "Remove: heap is already empty";
  }

  heapArray[0] = heapArray[heapArray.size()-1];
  heapArray.pop_back();
  heapify(0);
  //string fixup
}

void MinHeap::update (std::string item, int priority)
{
  int index = string_map.find(item);
  //cout << "update index = " << index << endl;
  heapArray[index]->setPriority(priority);
  
  // Check if this is less than its parent now.
  int parent = ( index - 1 ) / d;
  if( heapArray[parent]->getPriority() <= priority )
  {
    heapify( index );
  }
  else
  {
    decreaseKey( index, priority );
  }
  //string fixup 	
}

bool MinHeap::isEmpty()
{
  return heapArray.empty();
}

void MinHeap::print()
{
  for(vector<MapNode*>::iterator it = heapArray.begin();it!=heapArray.end();++it)
  {
    std::cout << (*it)->getString() << " , " << (*it)->getPriority() << std::endl;
  }
}

void MinHeap::string_fix(int parent)
{
  //string fixup AKA NEW STUFF ADDED


  for(int i = 1; i <= d; i++)
  {
    
    int child_index = d*parent+i;
    //cout << "testing 1" << endl;
    if(child_index< heapArray.size())
      {
	//cout << "testing 2" << endl;
	if(heapArray[child_index]->getPriority() == heapArray[parent]->getPriority())
	{
	  if(heapArray[child_index]->getString() < heapArray[parent]->getString())
	  {
	    //cout <<1<<endl;
	    MapNode* temp = heapArray[child_index];
	    const string indexString = temp->getString();
	    const string parentString = heapArray[parent]->getString();
	    heapArray[child_index] = heapArray[parent];
	    heapArray[parent] = temp;
	    
	    string_map.update(std::make_pair<string, int> (indexString, parent));
	    string_map.update(std::make_pair<string, int> (parentString, child_index));
	    heapify(parent);
	    string_fix(parent);
	  }
	}
	//else return; //?????
      }
    else break;
  }
  
  //END OF NEW
}
// MinHeap::
// MinHeap::
// MinHeap::
// MinHeap::
