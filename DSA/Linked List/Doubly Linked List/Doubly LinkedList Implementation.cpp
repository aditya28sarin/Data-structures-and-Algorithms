#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

//Inserting at the begining in Doubly Linked list 
void insertAtBegining(Node** head_ref, int data)
{
    Node* new_node =new Node();

    new_node->data=data;
    new_node->next =(*head_ref);
    new_node->prev=NULL;

    if((*head_ref)!=NULL)
    (*head_ref)->prev=new_node;

    (*head_ref)=new_node;
}


//Inserting at node in Doubly Linked List 
void insertAtEnd(Node** head_ref, int data)
{
    Node* temp = (*head_ref);
    Node* new_node = new Node();

    new_node->data=data;
    new_node->next=NULL;

    if((*head_ref)==NULL)
        (*head_ref)=new_node;
        new_node->prev=NULL;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
  
    temp->next=new_node;
    new_node->prev=temp;  
}


//Inserting After a given node in Doubly Linked List 
void afterGivenNode(Node** head_ref, int data, int pos)
{
    Node* ptr =(*head_ref);
    Node* ptr1=(*head_ref)->next;
    int c=0;

    while(ptr!=NULL)
    {
        c++;
      if(c==pos)
        {
            break;
        }
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    Node* new_node=new Node();
    new_node->data=data;
    
    ptr->next=new_node;
    new_node->prev=ptr;
    new_node->next=ptr1;
    ptr1->prev=new_node;    
    
}

//inserting before a given node
void beforeGivenNode(Node** head_ref,int data, int pos)
{
     Node* ptr =(*head_ref)->next;
    Node* ptr1=(*head_ref);
    int c=0;

    while(ptr!=NULL)
    {
        c++;
      if(c==pos)
        {
            break;
        }
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    Node* new_node=new Node();
    new_node->data=data;

    new_node->prev=ptr1;
    new_node->next=ptr;
    ptr1->next=new_node;
    ptr->prev=new_node;

}


//deleting a ndoe from Doubly Linked List
void deleteNode( Node** head_ref, int pos)
{
   

    if(pos==1)
    {
        (*head_ref)=(*head_ref)->next;   
    }
    Node* next_ptr =(*head_ref)->next;
    Node* prev_ptr=NULL;
    Node* curr_ptr=(*head_ref);
    int c=0;
    
    while(curr_ptr!=NULL)
    {
        c++;
      if(c==pos)
        {
            break;
        }
        prev_ptr=curr_ptr;
        curr_ptr=curr_ptr->next;
        next_ptr=next_ptr->next;
    }

    cout<<prev_ptr->data<<endl;
    cout<<curr_ptr->data<<endl;
    cout<<next_ptr->data<<endl;
}

//printing Doubly Linked List 
void printDoublyLinkedList(Node** head_ref)
{
    Node* temp=(*head_ref);

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head;

    insertAtBegining(&head,10);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,20);
    printDoublyLinkedList(&head);

    insertAtEnd(&head,50);
    printDoublyLinkedList(&head);

    afterGivenNode(&head,55,1);
    printDoublyLinkedList(&head);

    beforeGivenNode(&head,188,2);
    printDoublyLinkedList(&head);

    deleteNode(&head,2);

}