#include<bits/stdc++.h>
using namespace std;

/* Link list node */
class Node { 
public: 
    int data; 
    Node* next; 
}; 



int getCount(Node** head_ref);

int getIntesectionNode(Node* head1, Node* head2)
{

int len_list1=getCount(&head1);
int len_list2=getCount(&head2);

int len_diff=abs(len_list1-len_list2);

Node* ref_ptr1;
Node* ref_ptr2;


if(len_list1>len_list2)
{
    ref_ptr1=head1;
    ref_ptr2=head2;
}
else
{
    ref_ptr1=head2;
    ref_ptr2=head1;
}

int count=1;
    for(int i=0;i<len_diff;i++)
    {
        if(ref_ptr1==NULL)
            return -1;
        
        ref_ptr1=ref_ptr1->next;
    }

    while(ref_ptr1!=NULL || ref_ptr2!=NULL)
    {
        if(ref_ptr1==ref_ptr2)
            return ref_ptr1->data;

            ref_ptr1=ref_ptr1->next;
            ref_ptr2=ref_ptr2->next;
    }
    return -1;
}


int getCount(Node** head_ref)
{
    Node* temp=(*head_ref);
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int main() 
{ 
  
    Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    cout << "The node of intersection is " << getIntesectionNode(head1, head2); 
} 