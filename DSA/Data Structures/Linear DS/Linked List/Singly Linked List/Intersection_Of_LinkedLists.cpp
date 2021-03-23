#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int data)
{
    Node* new_node=new Node();

    new_node->data =data;

    new_node->next=(*head_ref);

    (*head_ref)=new_node;

}

Node* sortedIntersect(Node* head1, Node* head2)
{

    Node* intersect=new Node();
    Node* temp1=head1;
    Node* temp2=head2;
    Node* temp3=intersect;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            push((&temp3->next), temp1->data);
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data<temp2->data)
            temp1=temp1->next;
        else if (temp1->data>temp2->data)
             temp2=temp2->next;
    }

    return intersect->next;
}

void printList( Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersect = NULL;


    /* 1->2->3->4->5->6 */
    push(&head1, 6);
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);
Node* 
    printList(head1);

    /* 2->4->6->8 */
    push(&head2, 8);
    push(&head2, 6);
    push(&head2, 4);
    push(&head2, 2);

    printList(head2);

    /* Find the intersection two linked lists */
    intersect = sortedIntersect(head1,head2);

    printf("\n Linked list containing common items of Linked List 1 & Linked List 2: ");
    printList(intersect);

    return 0;
}
