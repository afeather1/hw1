/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

Node* generateList(int values[], int n){
	Node* head = NULL;
	Node* tail = NULL;

	for(int i = 0; i < n; i++){
		Node* newNode = new Node(values[i], NULL);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;
}

void printAndDeleteNodes(const char* name, Node* list){
	cout << name << ": ";
	while (list != NULL){
		cout << list->value << " ";
		Node* deleteThis = list;
		list = list->next;
		delete deleteThis;
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
// The test cases will consist of a list of regular values, all odd values,
// all even values, a single value, and no values (an empty list)
//

// Test of Regular values
//
{
	int values[] = {1, 2, 3, 4, 5, 6};
	Node* in = generateList(values, 6);
	Node* odds = NULL;
	Node* evens = NULL;
	split(in, odds, evens);
	cout << "Testing regular values:..." << endl;
	printAndDeleteNodes(" odds ", odds);
	printAndDeleteNodes(" evens ", evens);
	cout << " is in Null?: " << endl;
	if(in == NULL){
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

// Test of Empty List
//
{
	Node* in = NULL;
	Node* odds = NULL;
	Node* evens = NULL;
	split(in, odds, evens);
	cout << "Testing no values (empty list):..." << endl;
	cout << " are odds null?: ";
	if(odds == NULL){
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

// Test of All Odds
//
{
	int values[] = {1, 3, 5, 7};
	Node* in = generateList(values, 4);
	Node* odds = NULL;
	Node* evens = NULL;
	split(in, odds, evens);
	cout << "Testing all ODD values:..." << endl;
	printAndDeleteNodes(" odds ", odds);
	printAndDeleteNodes(" evens ", evens);
}

// Test of All Evens
//
{
	int values[] = {2, 4, 6, 8};
	Node* in = generateList(values, 4);
	Node* odds = NULL;
	Node* evens = NULL;
	split(in, odds, evens);
	cout << "Testing all EVEN values:..." << endl;
	printAndDeleteNodes(" odds ", odds);
	printAndDeleteNodes(" evens ", evens);
}

// Test of Just Inputting a Single Value
//
{
	int values[] = {1};
	Node* in = generateList(values, 1);
	Node* odds = NULL;
	Node* evens = NULL;
	split(in, odds, evens);
	cout << "Testing just a SINGLE value:..." << endl;
	printAndDeleteNodes(" odds ", odds);
	printAndDeleteNodes(" evens ", evens);
}
	return 0;
}
