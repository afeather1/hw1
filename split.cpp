/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

// The function recurses on the rest of the list before it
// sorts the current node. Essentially, the base case (NULL) is reached first
// and then with each recursive call, the current node gets attached to the
// beginning of the front of evens or odds depending on whether itself is even or odd.
// In this way, no nodes are being added or deleted.

void split(Node*& in, Node*& odds, Node*& evens)
{
// If there's no input (AKA in == NULL), return the empty list.
// This serves as the BASE CASE for the recursive function:
	if (in == NULL){
		return;
	}

// If the list is NOT empty, proceed with the following:
// 
	Node* head = in; // stores the first node of the list
	in = in->next; // detaches the first node from the rest of the list by moving the pointer forward 1 node

// Split everthing after the head node:
//
	split(in, odds, evens);

// Determine whether the head is even or odd, and append to front of corresponding list
//
	if(head->value % 2 == 0){ // head is thus even and is added to the front of the "evens" list
		head->next = evens;
		evens = head;
	}
	else { // head must therefore be odd
		head->next = odds;
		odds = head;
	}
}

