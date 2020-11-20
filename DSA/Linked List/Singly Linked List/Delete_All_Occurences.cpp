#include <bits/stdc++.h> 
  
using namespace std; 
  
/* a node of the doubly linked list */
struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev; 
}; 


void deleteNode(Node** head_ref, Node* del)
{
    if((*head_ref)==NULL || del==NULL)
        return;

    if((*head_ref)==del)
        (*head_ref)=del->next;

    if(del->next!=NULL)
        del->next->prev=del->prev;
    
    if(del->prev!=NULL)
        del->prev->next=del->next;

    free(del);
}


void deleteAllOccurOfX(Node** head_ref, int data)
{
    if((*head_ref)==NULL)
        return;

    Node* temp = (*head_ref);
    Node* next;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            next=temp->next;
            deleteNode(head_ref,temp);
            temp=next;
        }
        else
        {
            temp=temp->next;
        }
        
    }
}
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node =  
             (struct Node*)malloc(sizeof(struct Node)); 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* since we are adding at the beginning, 
    prev is always NULL */
    new_node->prev = NULL; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* change prev of head node to new node */
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
/* Function to print nodes in a given doubly 
   linked list */
void printList(struct Node* head) 
{ 
    /* if list is empty */
    if (head == NULL) 
        cout << "Doubly Linked list empty"; 
  
    while (head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    /* Create the doubly linked list: 
           2<->2<->10<->8<->4<->2<->5<->2 */
    push(&head, 2); 
    push(&head, 5); 
    push(&head, 2); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 10); 
    push(&head, 2); 
    push(&head, 2); 
  
    cout << "Original Doubly linked list: "; 
    printList(head); 
  
    int x = 2; 
  
    /* delete all occurrences of 'x' */
    deleteAllOccurOfX(&head, x); 
  
    cout << "\nDoubly linked list after deletion of "
         << x <<": "; 
    printList(head); 
  
    return 0; 
} 