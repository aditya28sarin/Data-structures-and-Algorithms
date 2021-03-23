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


Node* reverseByN(Node* head, int n)
{
	Node* temp=head; 
	Node* temp1=head;
	Node* prev_head=head;
	while(temp!=NULL)
	{
		n--;
		if(n==0)
		{
			temp1=temp->next;
			temp->next=NULL;
			temp1->prev=NULL;
			temp=temp1;
			head=temp;
		}

		if(temp->next==NULL)
		{
			temp->next=prev_head;
			prev_head->prev=temp;
		}
		temp=temp->next;
	}

	return head;

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

    insertAtBegining(&head,10);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,20);
    printDoublyLinkedList(&head);

   	insertAtBegining(&head,30);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,40);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,50);
    printDoublyLinkedList(&head);

    insertAtBegining(&head,60);
    printDoublyLinkedList(&head);

    reverseByN(head,2);
	printDoublyLinkedList(&head);

}