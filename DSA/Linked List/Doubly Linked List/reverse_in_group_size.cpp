// URL:https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/

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


void push(Node** head_ref, Node* new_node)
{
    new_node->prev=NULL;
    
    new_node->next=(*head_ref);
    
    if((*head_ref)!=NULL)
        (*head_ref)->prev=new_node;
        
    (*head_ref)=new_node;
}

Node* reverseDLLByGroup(Node* head, int k)
{
    Node* currPtr=head;
    Node* nextPtr=NULL;
    Node* new_head=NULL;
    int count=0;
    while(currPtr!=NULL && count<k)
    {
        nextPtr=currPtr->next;
       push(&new_head,currPtr);
        currPtr=nextPtr;
        count++;

    }

    if(nextPtr!=NULL)
    {
        head->next=reverseDLLByGroup(nextPtr,k);
        head->next->prev=head;
    }

    return new_head;
}



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

    insertAtBegining(&head,2);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,4);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,8);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,10);
    printDoublyLinkedList(&head);

    head=reverseDLLByGroup(head,2);
    printDoublyLinkedList(&head);

}