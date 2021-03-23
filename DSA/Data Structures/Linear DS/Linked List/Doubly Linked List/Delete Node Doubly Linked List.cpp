#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
};


void push(Node** head_ref, int data)
{
    Node* new_node=new Node();
    
    new_node->prev=NULL;

    new_node->data=data;
   
    new_node->next=(*head_ref);

    if(*head_ref!=NULL)
        (*head_ref)->prev=new_node;

    (*head_ref)=new_node;
    
}

void deleteNode(Node** head_ref, int del_pos)
{
    int c=0;
    Node* temp=(*head_ref);
    while(temp!=NULL)
    {
        c++;
        if(c==del_pos-1)
        {
            break;
        }
        temp=temp->next;
    }

    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    
    //cout<<c<<" "<<temp->data;
}

void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
} 
  

int main()
{
     struct Node* head = NULL; 
  
    /* Create the doubly linked list 10<->8<->4<->2<->5 */
    push(&head, 5); 
    push(&head, 2); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 10); 

    

     cout << "Doubly linked list before deletion:n"; 
    printList(head); 
  
    int n = 2; 
  
    /* delete node at the given position 'n' */
     deleteNode(&head,n);
  
    cout << "\nDoubly linked list after deletion:n"; 
    printList(head); 
  
}