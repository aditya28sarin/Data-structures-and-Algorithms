#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
class Node { 
public: 
    int data; 
    Node* next; 
}; 

Node* sortedMerge(Node* a, Node* b)
{
    Node* result;

    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    if(a->data <= b->data)
    {
        result=a;
        result->next=sortedMerge(a->next,b);
    }

    if(a->data > b->data)
    {
        result=b;
        result->next=sortedMerge(a,b->next);
    }

    return result;   
}

void frontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast=source->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }

    (*frontRef)=source;
    (*backRef)=slow->next;
    slow->next=NULL;
}

void mergeSort(Node** head_ref)
{
    Node* head=(*head_ref);
    Node* a;
    Node* b;

     if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 

    frontBackSplit(head,&a,&b);

    mergeSort(&a);
    mergeSort(&b);

    (*head_ref)=sortedMerge(a,b);

}

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  
int main() 
{ 
    Node* res = NULL; 
    Node* head = NULL; 
  
 /* Created lists shall be a: 2->3->20->5->10->15 */
    push(&head, 15); 
    push(&head, 10); 
    push(&head, 5); 
    push(&head, 20); 
    push(&head, 3); 
    push(&head, 2); 
  
    mergeSort(&head); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(head); 
  
    return 0; 
} 