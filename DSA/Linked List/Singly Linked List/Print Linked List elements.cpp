#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    Node* next;
};


void printList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main()
{

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head -> data=1;
    head -> next=second;

    second -> data =2;
    second -> next =third;

    third -> data=3;
    third -> next=NULL;

    printList(head);
}





