#include<iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node* prev;
};



Node* push(Node* head, int data)
{
    Node* new_node=new Node();

    new_node->data=data;

    new_node->next=head;
    if(head!=NULL)
    head->prev=new_node;
    new_node->prev=NULL;
    head=new_node;

    return head;

}

Node* append(Node* head,int data)
{

     Node* new_node=new Node();

    new_node->data=data;

    new_node->next=NULL;

    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    else
    {
        Node* ptr =head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
            ptr->next=new_node;
            new_node->prev=ptr;
            return head;
    }
}


void insertAfter(Node* prev_node, int data)
{

    if(prev_node==NULL)
    {
        return;
    }

    Node* new_node=new Node();

    new_node->data=data;

    new_node->next=prev_node->next;
    prev_node->next=new_node;
    new_node->prev=prev_node;
    if(new_node->next!=NULL)
    new_node->next->prev=new_node;
}

Node* insertBefore(Node* head, Node* next_node, int data)
{
    if(next_node==NULL)
    {
        return head;
    }
    else
    {
    Node* new_node=new Node();

    new_node->data=data;

    new_node->prev=next_node->prev;
    new_node->next=next_node;
    next_node->prev=new_node;
    if(new_node->prev!=NULL)
    new_node->prev->next=new_node;
    else
        head=new_node;

        return head;
    }
}


void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }

    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->prev;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    head=append(head, 6);

    // Insert 7 at the beginning. So
    // linked list becomes 7->6->NULL
    head=push(head, 7);

    // Insert 1 at the beginning. So
    // linked list becomes 1->7->6->NULL
    head=push(head, 1);

    // Insert 4 at the end. So linked
    // list becomes 1->7->6->4->NULL
    head=append(head, 4);

    head=insertBefore(head,head->next,88);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout << "Created DLL is: ";
    printList(head);

    return 0;
}
