#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  smaller = nullptr;
  larger = nullptr; 
  llpivotHelper(head, smaller, larger, pivot);
  head = nullptr; 
}

void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head == nullptr){
    return; //base case return when list is empty 
  }
  Node* next = head->next; //set next to the next value 
  if (head->val > pivot) { 
    larger = head; //if head value larger than pivot, add it to head 
    llpivot(next, smaller, larger->next, pivot);
  } 
  else if (head->val<= pivot){
    smaller = head; //if head value larger or equal to pivot, add it to head
    llpivot(next, smaller->next, larger, pivot);
  }
}
