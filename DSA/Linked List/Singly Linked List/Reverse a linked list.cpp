#include<iostream>
using namespace std;



struct Node
{

public:
    int data;
    Node* next;
};


Node* Reverse(Node* head)
{

    Node* currPtr=head;
    Node* prevPtr=NULL;
    Node* nextPtr=head;


    while(currPtr!=NULL)
    {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    head=prevPtr;

    return head;
}

Node* Insert(Node* head, int data)
{
    Node* ptr =head;
    Node* n=new Node();
    n->data=data;

    if(head==NULL)
    {
        head=n;
        return head;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
        n->next=NULL;
        return head;
    }

}

void Print(Node* head)
{
    Node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main ()
{
Node* head =NULL;

head=Insert(head,1);
head=Insert(head,2);
head=Insert(head,3);
head=Insert(head,4);
head=Insert(head,5);
head=Insert(head,5);
head=Insert(head,7);
Print(head);
head=Reverse(head);
Print(head);



}
