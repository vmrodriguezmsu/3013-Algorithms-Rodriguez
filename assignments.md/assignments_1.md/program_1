/*
Title:
	Program 1
Files:
	main.cpp
Semester:
	CMPS 3013--Spring 2018
Author: 
	Vincent Rodriguez
Email:
	foxsoccer11@yahoo.com
Description:
	The purpose of this program is to use a priority queue
	to hold a list of integers ranging from 0 - 99. When the program
	runs, it will create the container for this list and a pointer
	called Head. Afterwards, the program will generate random numbers
	(modulo 100) and use the orderedSert method to keep the integers
	in order according to their values and when they were received
	into the list.
*/
#include <iostream>
#include <ctime>

using namespace std;

//Create a container for our list data
struct node {
	int data;
	node* next;
};

/*
* Class: intLinkedList
* Purpose:
*     Implements a singly linked list that holds integers.
* Methods:
*     void  frontSert(int x)
*     node* find(int key)
*     node* remove(int key)
*     void  print()
*	  void orderedSert(int x)
*/
class intLinkedList {
private:
	node* Head;
public:
	intLinkedList() {
		Head = NULL;
	}
	void frontSert(int x) {
		//empty list case
		if (!Head) {
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		else {//not empty list
			node* T = new node;
			T->data = x;
			T->next = Head;
			Head = T;
		}
	}

	node* Find(int key) {
		node* temp = Head;
		while (temp) {
			if (temp->data == key) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void Remove(int key) {
		node* result = Find(key);
		if (result) {
			node* temp = Head;
			while (temp->next != result) {
				temp = temp->next;
			}
			temp->next = result->next;
			delete result;
		}
	}

	void print() {
		node* p = Head;
		while (p) {
			cout << p->data << endl;
			p = p->next;
		}
	}

	void orderedSert(int x) {
		bool inserted = false;

		//if list is empty
		if (!Head)
			frontSert(x);

		//if list is not empty
		else {
			node * tmp = Head;
			while (tmp->data < x && !inserted) {

				//if tmp next pointer not pointing to NULL and integer less than x
				if (tmp->next != NULL && (tmp->next)->data < x)
					tmp = tmp->next;
				else {
					if (tmp->next == NULL) {
						tmp->next = new node;
						tmp = tmp->next;
						tmp->data = x;
						tmp->next = NULL;
						inserted = true;
					}

					//tmp->next not pointing to NULL
					else{
						node *t = tmp->next;
						tmp->next = new node;
						tmp = tmp->next;
						tmp->data = x;
						tmp->next = t;
						inserted = true;
					}
				}
			}

			if (tmp->data > x) {
				Head = new node;
				Head->data = x;
				Head->next = tmp;
				inserted = true;
			}

			/*
			node being inserted has the same integer value as tmp->data.
			node that was inserted in queue first will precede the new
			inserted node.
			*/
			if (!inserted) {
				tmp = new node;
				tmp->data = x;
				tmp->next = Head->next;
				Head->next = tmp;
			}
		}
	}
};

int main() {
	// seed random number generator
	srand(8734587);

	// ummmm
	cout << "Hello World!\n";

	// declare instance of intLinkedList turning
	// a class definition into an "object"
	intLinkedList mylist;

	//Load 10 random ints into our list
	for (int i = 0; i<10; i++) {
	//	mylist.frontSert(rand() % 100);
		mylist.orderedSert(rand() % 100);
	}

	//print the list
	mylist.print();

	//find some value
	cout << mylist.Find(99) << endl;

	//remove some value 
	mylist.Remove(58);

	//print the list again
	mylist.print();

	system("pause");
}
