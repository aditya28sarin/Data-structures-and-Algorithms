#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
};

void push(Node** head, int data)
{

    Node* new_node=new Node();
    new_node->data=data;

    new_node->next=*head;
    *head=new_node;

}


void printList(Node* head)
{
    Node* ptr=head;

    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}

void moveToFront(Node** head)
{

    Node* ptr1=*head;
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }
    int temp;
    temp=ptr1->data;
    ptr1->data=(*head)->data;
    (*head)->data=temp;


}


/* Driver code */
int main()
{
    Node *start = NULL;

    /* The constructed linked list is:
    1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout<<"Linked list before moving last to front\n";
    printList(start);

    moveToFront(&start);

    cout<<"\nLinked list after removing last to front\n";
    printList(start);

    return 0;
}
