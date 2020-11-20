
#include <bits/stdc++.h> 
using namespace std;  

class Node  
{  
    public: 
    int key;  
    Node* next;  
};  
  

void push(Node** head_ref, int new_key)  
{  
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the key */
    new_node->key = new_key;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  

//iterative
bool search(Node* head,int key)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        if(temp->key==key)
            return true;
        temp=temp->next;
    }
    return false;
}

//recursive
bool searchBool(Node* head,int key)
{
    Node* temp=head;

    if(temp==NULL)
        return false;

    if(key==temp->key)
        return true;

    search(temp->next,key);
    
}


int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
    int x = 10;  
  
    /* Use push() to construct below list  
    14->21->11->30->10 */
    push(&head, 10);  
    push(&head, 30);  
    push(&head, 11);  
    push(&head, 21);  
    push(&head, 14);  
  
    search(head, x)? cout<<"Yes" : cout<<"No"<<endl;  

    searchBool(head, x)? cout<<"Yes" : cout<<"No";  
    return 0;  
}  