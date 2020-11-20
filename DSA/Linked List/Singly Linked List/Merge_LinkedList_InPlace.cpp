#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public:
    int data; 
    Node* next; 
}; 
  
Node* newNode(int key) 
{ 
     Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
void printList( Node* node) 
{ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 


Node* mergeUtil(Node* head1, Node* head2)
{
    if(!head1->next)
    {
        head1->next=head2;
        return head1;
    }

    Node* curr1=head1; 
    Node* next1=head1->next;

    Node* curr2=head2; 
    Node* next2=head2->next;

    while(next1 && curr2)
    {
        if((curr2->data) >= (curr1->data) && (curr2->data) <= (next1->data))
        {
            next2=curr2->next;
            curr1->next=curr2;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else
        {
            if(next1->next)
            {
                next1=next1->next;
                curr1=curr1->next;
            }
            else
            {
                next1->next=curr2;
                return head1;
            }
            
        }
        
        
    }
    return head1;
}


//recursive 

// Node* merge(Node* h1, Node* h2) 
// { 
//     if (!h1) 
//         return h2; 
//     if (!h2) 
//         return h1; 
  
//     // start with the linked list 
//     // whose head data is the least 
//     if (h1->data < h2->data) { 
//         h1->next = merge(h1->next, h2); 
//         return h1; 
//     } 
//     else { 
//         h2->next = merge(h1, h2->next); 
//         return h2; 
//     } 
// } 


Node* merge(Node* head1, Node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    if(head1->data < head2->data)
        return mergeUtil(head1, head2);
    else
    {
        return mergeUtil(head2,head1);
    }
    
}

int main() 
{ 
     Node* head1 = newNode(1); 
    head1->next = newNode(3); 
    head1->next->next = newNode(5); 
  
    // 1->3->5 LinkedList created 
  
     Node* head2 = newNode(0); 
    head2->next = newNode(2); 
    head2->next->next = newNode(4); 
  
    // 0->2->4 LinkedList created 
  
     Node* mergedhead = merge(head1, head2); 
  
    printList(mergedhead); 
    return 0; 
} 