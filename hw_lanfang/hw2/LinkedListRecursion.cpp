#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

void split(Node*& in, Node*& smaller, Node*& larger, int pivot)
{
	if(in == NULL) 
	{
		cout << "check1" << endl;
		return;
	}
	if(in->value <= pivot) 
	{
		cout << "check2" << endl;
		Node* temp = in;
		in = in->next;
		temp->next = smaller;
		smaller = temp;
	}	
	else if(in->value > pivot)
	{
		cout << "check3" << endl;
		Node* temp2 = in;
		in = in->next;
		temp2->next = larger; 
		larger = temp2;
	}
	split(in, smaller, larger, pivot);
}

int main()
{
	Node * in = NULL;
	Node * smaller = NULL;
	Node * larger = NULL; //Initialize all the Linked Lists 
    int i;
    for(i=1;i<=10;i++) { //places individual numbers into the 'in' Linked List
    	Node * curr = new Node;
    	curr->value = rand()%100;
    	curr->next  = in;
    	in = curr;
    }


    split(in, smaller, larger, 50);

 	cout << "Smaller: ";
   	while(smaller) {
    	cout << smaller->value << " ";
    	smaller = smaller->next ;
    }
    cout << endl;

    cout << "Larger: ";
    while(larger) {
    	cout << larger->value << " ";
    	larger = larger->next ;
    }
    cout << endl;
    return 0;
}

