#include <bits/stdc++.h>
using namespace std;
 
class Node 
{ 
    public:
    int data; 
    Node* next; 
}; 

// merge into separate list without reference 
Node* sortedMerge(Node* head1, Node* head2)
{
    Node list_start=Node();
    list_start.data=-1;
    list_start.next=NULL;
    
    Node* ptr= & list_start;
    
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            ptr->next=head1;
            ptr=head1;
            head1=head1->next;
        }
        else
        {
            ptr->next=head2;
            ptr=head2;
            head2=head2->next;
        }
    }

    if(head1!=NULL)
        ptr->next=head1;
 
    if(head2!=NULL)
        ptr->next=head2;

        return list_start.next;
}


// without using dummy node
Node* sortedMergeRef(Node* head1, Node* head2)
{
    Node* sort=NULL;
    Node* new_head=NULL;

    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    if(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            sort=head1;
            head1=head1->next;
        }
        else
        {
            sort=head2;
            head2=head2->next;
        }
    }
    new_head=sort;

    while( head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            sort->next=head1;
            sort=head1;
            head1=sort->next;
        }
        else
        {
            sort->next=head2;
            sort=head2;
            head2=sort->next;
        }
    }

        if(head1!=NULL)
        {
            sort->next=head1;
        }
        
        if(head2!=NULL)
        {
            sort->next=head2;
        }
    return new_head;
}

//merge in new linked list recursive 
Node* mergeRecursive(Node* head1, Node* head2)
{
    Node* result =NULL;

    if(head1==NULL)  
        return head2;
    else if(head2==NULL)
        return head1;

    if(head1->data <= head2->data)
    {
        result = head1;
        result->next=mergeRecursive(head1->next, head2);
    } 
    else
    {
        result=head2;
        result->next= mergeRecursive(head1, head2->next);
    }
    return result;
}

void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node();
 
    new_node->data = new_data; 
 
    new_node->next = (*head_ref); 
 
    (*head_ref) = new_node; 
} 
 
void printList(Node *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->next; 
    } 
} 
 
int main() 
{ 
    /* Start with the empty list */
    Node* res = NULL; 
    Node* head1 = NULL; 
    Node* head2 = NULL; 
 
 
  
    push(&head1, 15); 
    push(&head1, 10); 
    push(&head1, 5); 
 
    push(&head2, 20); 
    push(&head2, 3); 
    push(&head2, 2); 
 
    /* Remove duplicates from linked list */
    res = sortedMergeRef(head1,head2); 
 
    cout << "Merged Linked List is: \n"; 
    printList(res); 
 
    return 0; 
}