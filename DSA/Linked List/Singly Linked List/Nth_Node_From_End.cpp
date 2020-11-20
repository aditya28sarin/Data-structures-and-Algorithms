#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
    int data;
    Node* next;
};

int getNthFromLast(Node *head, int n)
{      int c=0;
       Node* ptr=head;
       while(ptr!=NULL)
       {
           ptr=ptr->next;
           c++;
       }
       Node* ptr2=head;
       int k=0;
       while(ptr2!=NULL)
       {
           if(c-n==k)
           {
               return ptr2->data;
           }
           ptr2=ptr2->next;
           k++;
       }
       return -1;


}
//2 pointer concept 
int printNthFromLast(Node* head, int nth_node)
{
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    int step=0;

    while(fast_ptr!=NULL)
    {
      if(step<nth_node)
      {
        fast_ptr=fast_ptr->next;
        step++;
      }
      else
      {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next;
      }
      
    }
    return slow_ptr->data;
}

void push(struct Node** head_ref, int new_data) 
{ 
  struct Node* new_node = new Node();  
  
  new_node->data  = new_data; 
  
  new_node->next = (*head_ref);     
  
  (*head_ref) = new_node; 
} 
  

int main() 
{ 
  /* Start with the empty list */
  struct Node* head = NULL; 
  push(&head, 20); 
  push(&head, 4); 
  push(&head, 15); 
  push(&head, 35); 
  
  int val = getNthFromLast(head,3);

  cout<<val<<endl;

  int val2=printNthFromLast(head, 2); 

  cout<<val2<<endl;
} 