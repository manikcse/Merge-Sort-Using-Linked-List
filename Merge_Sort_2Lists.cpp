#include <iostream>
using namespace std;

//Name: Manik Debnath
//Student ID.: 2021124913


// creating Node
struct Node {
	int key;
	struct Node* next;
};

// Function to reverse given Linked List using Recursion

Node* reverseList(Node* head)
{

	if (head->next == NULL)
		return head;

	Node* rest = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;

	return rest;
}

// Given two non-empty linked lists 'Sorted_List1' and 'Sorted_List2'

Node* sortedMerge(Node* Sorted_List1, Node* Sorted_List2)
{

// Reverse Linked List 'Sorted_List1'

	Sorted_List1 = reverseList(Sorted_List1);

// Reverse Linked List 'Sorted_List2'

	Sorted_List2 = reverseList(Sorted_List2);

// Initialize head of resultant list

	Node* head = NULL;

	Node* temp;

// Traverse both lists

	while (Sorted_List1 != NULL && Sorted_List2 != NULL) {

// If Sorted_List1's current value is greater than or equal to Sorted_List2's current value.

		if (Sorted_List1->key >= Sorted_List2->key) {

// Store next of current Node in first list

			temp = Sorted_List1->next;
		
// Add 'Sorted_List1' at the front of resultant list

			Sorted_List1->next = head;
		
// Make 'Sorted_List1' - head of the result list

			head = Sorted_List1;
		
// Move ahead in first list

			Sorted_List1 = temp;
		}
			
		else {

			temp = Sorted_List2->next;
			Sorted_List2->next = head;
			head = Sorted_List2;
			Sorted_List2 = temp;
		}
	}

// If second list reached end, but first list has nodes. 
//Add remaining nodes of first list at the beginning of result list

	while (Sorted_List1 != NULL) {

		temp = Sorted_List1->next;
		Sorted_List1->next = head;
		head = Sorted_List1;
		Sorted_List1 = temp;
	}

// If first list reached end, but second list has nodes. 
//Add remaining nodes of second list at the beginning of result list

	while (Sorted_List2 != NULL) {

		temp = Sorted_List2->next;
		Sorted_List2->next = head;
		head = Sorted_List2;
		Sorted_List2 = temp;
	}
	return head;
}

//Function to print Nodes in linked list
void printList(struct Node* Node)
{
	while (Node != NULL) {
		cout << Node->key << " ";
		Node = Node->next;
	}
}

// function to create a new node with given key
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

//testing the 2 lists to merge them in one big sorted list as below in main function:- 


int main()
{
	
// Start with the empty list 
	struct Node* res = NULL;

//create two lists Sorted_List1 , Sorted_List2
	Node* Sorted_List1 = newNode(15);
	Sorted_List1->next = newNode(17);
	Sorted_List1->next->next = newNode(26);
	Sorted_List1->next->next->next = newNode(41);
	Sorted_List1->next->next->next->next = newNode(44);
	Sorted_List1->next->next->next->next->next = newNode(48);
	Sorted_List1->next->next->next->next->next->next = newNode(80);

	Node* Sorted_List2 = newNode(8);
	Sorted_List2->next = newNode(28);
	Sorted_List2->next->next = newNode(35);
	Sorted_List2->next->next->next = newNode(39);
	Sorted_List2->next->next->next->next = newNode(51);
	Sorted_List2->next->next->next->next->next = newNode(54);
	Sorted_List2->next->next->next->next->next->next = newNode(97);
    
	cout << "Sorted_List1: \n";
	printList(Sorted_List1);
	cout<<"\n";

	cout << "\nSorted_List2: \n";
	printList(Sorted_List2);
    cout<<"\n"; 
     
// merge 2 sorted Linked Lists
	res = sortedMerge(Sorted_List1, Sorted_List2);

	cout << "\nMerging The Two List into one big sorted list: \n";
	cout<<"\nFinal List is: \n";
	printList(res);

	return 0;
}

