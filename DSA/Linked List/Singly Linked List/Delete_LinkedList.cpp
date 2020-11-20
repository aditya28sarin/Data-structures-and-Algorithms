// C++ program to delete a linked list  
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  

void deleteList(Node** head_ref)
{
    Node* temp = (*head_ref);
    while(temp->next!=NULL)
    {
        temp=(*head_ref)->next;
        free((*head_ref));
        (*head_ref)=temp;
    }
}

void push(Node** head_ref, int data)
{
    Node* new_node=new Node();

    new_node->data=data;

    new_node->next=(*head_ref);

    (*head_ref)=new_node;

}



/* Driver code*/
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
      
    /* Use push() to construct below list  
    1->12->1->4->1 */
    push(&head, 1);  
    push(&head, 4);  
    push(&head, 1);  
    push(&head, 12);  
    push(&head, 1);  
      
    cout << "Deleting linked list";  
    deleteList(&head);  
      
    cout << "\nLinked list deleted";  
}  
  