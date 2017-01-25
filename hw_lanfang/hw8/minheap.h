#ifndef MINHEAP_H
#define MINHEAP_H
#include "hashtable.h"
#include <string>
#include <vector>


class MapNode;
class MinHeap {
     public:
      void print();
      void heapify(int index);
      void decreaseKey( int index, int priority );

       MinHeap (int d);
       /* Constructor that builds a d-ary Min Heap
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/



       ~MinHeap ();

       void add (std::string item, int priority);
         /* adds the item to the heap, with the given priority. */

       const std::string & peek () const;
         /* returns the element with smallest priority.  If
            multiple items have the smallest priority, it returns
            the string which comes first alphabetically.
            Throws an exception if the heap is empty. */

       void remove ();
         /* removes the element with smallest priority.  If
            multiple items have the smallest priority, it removes
            the string which comes first alphabetically.
            Throws an exception if the heap is empty. */

       void update (std::string item, int priority);
         /* updates the priority for the specified element.
            You may want this function to do nothing if the new 
            priority is higher than the old one.
            Throws an exception if the item is not in the heap. */  

       bool isEmpty ();
         /* returns true iff there are no elements on the heap. */
       //new
       void string_fix(int parent);

   private:
    HashTable string_map;
    std::vector<MapNode*> heapArray;
    const int d;



      // whatever you need to naturally store things.
      // You may also add helper functions here.
  };
  class MapNode {
  public:
  MapNode(std::string str, int priority) : 
    str(str), priority(priority)
  {}
  int getPriority()
  {
    return priority;
  }
  const std::string & getString()
  {
    return str;
  }
  void setPriority(int newPriority)
  {
    priority = newPriority;
  }


  private:
    int priority;
    const std::string str;
  };




  #endif
