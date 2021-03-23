#include <bits/stdc++.h> 
using namespace std; 
  

class Node  
{  
    public: 
    int data;  
    Node* next;  
}; 

//iterative
Node* removeDuplicates(Node* head)
{
  Node* temp =head;
  Node* next_ptr=NULL;
  while(temp->next!=NULL)
  {
    if(temp->data==temp->next->data)
    {
      next_ptr=temp->next->next;
      delete(temp->next);
      temp->next=next_ptr;
    }
    else
    {
      temp=temp->next;
    }
  }
  return head;
} 


//recursive
Node* removeDuplicatesRecursive(Node* head)
{
  Node* temp =head;
  Node* next_ptr=NULL;
  
  if(temp->next==NULL)
    return head;
  
  if(temp->data==temp->next->data)
  {
    next_ptr=temp->next->next;
    delete(temp->next);
    temp->next=next_ptr;
    removeDuplicatesRecursive(temp);
  }
  else
  {
    removeDuplicatesRecursive(temp->next);
  }
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
        cout<<" "<<node->data;  
        node = node->next;  
    }  
    cout<<endl;
}  
  

int main()  
{  
    
    Node* head = NULL;  
      
    /* Let us create a sorted linked list to test the functions  
    Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);  
    push(&head, 13);  
    push(&head, 13);  
    push(&head, 11);  
    push(&head, 11);  
    push(&head, 11);                                      
  
    cout<<"Linked list before duplicate removal ";  
    printList(head);  
  
    /* Remove duplicates from linked list */
   head= removeDuplicates(head);  
   printList(head); 
    // cout<<"\nLinked list after duplicate removal ";      
    // printList(head); 

   head= removeDuplicatesRecursive(head);             

    // cout<<"\nLinked list after duplicate removal ";      
    // printList(head); 
      
    return 0;  
}  