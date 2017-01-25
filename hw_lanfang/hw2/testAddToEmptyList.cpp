#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  //INSERT
  // Insert an item at the head.
  list->insert(0, 3);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }
  //This is where I started adding stuff
  
  //Add to the end of the list (tail)
  list->insert(1, 5);
  
  if (list->size() == 2) {
    cout << "SUCCESS: List has size 2 after two insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after two insertion.";
    cout << endl;
  }
  // Check if the value is correct.
  if (list->get(1) == 5) {
    cout << "SUCCESS: 5 is at the 1st index of the list." << endl;
  } else {
    cout << "FAIL: 5 is not at the 1st index of the list, " << list->get(1);
    cout << " is instead." << endl;
  }
  
  //Add to the middle of the list
  list->insert(1, 4);
  
  if (list->size() == 3) {
    cout << "SUCCESS: List has size 3 after three insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after three insertion.";
    cout << endl;
  }
  // Check if the value is correct.
  if (list->get(1) == 4) {
    cout << "SUCCESS: 4 is at the 1st index of the list." << endl;
  } else {
    cout << "FAIL: 4 is not at the 1st index of the list, " << list->get(1);
    cout << " is instead." << endl;
  }
  // Check that the original value at the fist index is at the 2nd index now 
  if (list->get(2) == 5) {
    cout << "SUCCESS: 5 is now at the 2nd index of the list." << endl;
  } else {
    cout << "FAIL: 5 is not at the 2nd index of the list now, " << list->get(2);
    cout << " is instead." << endl;
  }
 
 //Add something to a location larger than size+1
   list->insert(4, 7);
  
  if (list->size() == 3) {
    cout << "SUCCESS: List still has size 3 after three acceptable insertion and one faulty insertion to a location larger than size+1." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after the faulty insertion.";
    cout << endl;
  }
  
   //Add something to a location larger than size+1
   list->insert(-1, -1);
  
  if (list->size() == 3) {
    cout << "SUCCESS: List still has size 3 after three acceptable insertion and another faulty insertion to a negative location." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after the faulty insertion.";
    cout << endl;
  }
  
  //REMOVE
  // Remove the item at the middle.
  list->remove(1);

  if (list->size() == 2) {
    cout << "SUCCESS: List has size 2 after one removal (MIDDLE REMOVAL)." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one removal.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(1) == 4) {
    cout << "FAIL: 4 is still at the 1st index of the list." << endl;
  } else {
    cout << "SUCCESS: 4 is not at the 1st index of the list, " << list->get(1);
    cout << " is instead." << endl;
  }
  
  //remove the end of the list (tail)
  list->remove(1);
  
  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after two removals (TAIL REMOVAL)." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after two removals.";
    cout << endl;
  }
   if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is still at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(1);
    cout << " is instead." << endl;
  }
  //Remove the head of the list
  list->remove(0);
  
  if (list->size() == 0) {
    cout << "SUCCESS: List has size 0 after three removals (HEAD REMOVAL)." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after three removals.";
    cout << endl;
  }



  

  // Clean up memory.
  delete list;
}
