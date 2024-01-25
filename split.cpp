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

/* Add a prototype for a helper function here if you need */
void insertSorted(Node*& head, Node* newNode);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // base case
  if(!in){
    return;
  }

  Node* next = in->next;

  in->next = nullptr;

  if(in->value % 2 == 0){
    insertSorted(evens, in);
  } else {
    insertSorted(odds, in);
  }

  split(next, odds, evens);

  in = nullptr;

}

/* If you needed a helper function, write it here */
void insertSorted(Node*& head, Node* newNode){
  if(!head || head->value >= newNode->value){
    newNode->next = head;
    head = newNode;
  } else{
    insertSorted(head->next, newNode);
  }
}