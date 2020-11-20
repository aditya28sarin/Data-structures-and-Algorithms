#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};



void insertNodeToEmpty(Node** head_ref, int data)
{
    if((*head_ref)==NULL)
    {
        Node* new_node=new Node();
        new_node->data=data;
        (*head_ref)=new_node;
        new_node->next=new_node;
    }
    else
    {
        return;
    }
}

void insertAtBegining(Node** head_ref, int data)
{
    Node* new_node = new Node();
    new_node->data=data;
    if((*head_ref)==NULL)
        insertNodeToEmpty(head_ref,(*head_ref)->data);

    new_node->next=(*head_ref)->next;
    (*head_ref)->next=new_node;
}

void insertAtEnd(Node** head_ref, int data)
{
    Node* new_node = new Node();
    new_node->data=data;
    if((*head_ref)==NULL)
        insertNodeToEmpty(head_ref,(*head_ref)->data);

    new_node->next=(*head_ref)->next;
    (*head_ref)->next=new_node;
    (*head_ref)=new_node;
}


Node* insertAfter(Node* head, int data, int item)
{
    if(head==NULL)
        return NULL;
    
    Node* start=head->next;
    Node* new_node=new Node();
    new_node->data=data;
    do{
        if(start->data==item)
        {
            new_node->next=start->next;
            start->next=new_node;

        }   
        start=start->next;
    }while(start!=head);
    
    return head->next;
}

void deleteNode(Node** head_ref, int key)
{
    if((*head_ref)==NULL)
        return;
    
    Node* curr=(*head_ref);
    Node* prev=NULL;

    while(curr->next!=(*head_ref))
    {
        prev=curr;
        curr=curr->next;

        if(curr->data==key)
        {
            //if only 1 node in the list
            if((*head_ref)->next==(*head_ref))
            {
                (*head_ref)==NULL;
                free(curr);
            }
            //if curr is first node
            if(curr==(*head_ref))
            {
                while(prev->next!=(*head_ref))
                {
                    prev=prev->next;
                }
                (*head_ref)=(*head_ref)->next;
                prev->next=(*head_ref);
                delete(curr);
            }
            //if curr is last node
            else if(curr->next==(*head_ref))
            {
                prev->next=(*head_ref);
                delete(curr);
            }
            else
            {
                prev->next=curr->next;
                delete(curr);
            }
            


        }
    }
    
}

void printList(Node* head)
{
    Node* temp = head;

    if(head!=NULL)
    {
        do{ 
            cout<<temp->data<<" ";
            temp=temp->next;

        }while(temp!=head);
    }
    cout<<endl<<endl;
}


int main()
{
    Node *last = NULL; 
  
    insertNodeToEmpty(&last, 6); 
    insertAtBegining(&last, 4); 
    insertAtBegining(&last, 2); 
    insertAtEnd(&last, 8); 
    insertAtEnd(&last, 12); 
    last=insertAfter(last, 10, 8); 
  
    printList(last);  
    int key=8;
    deleteNode(&last, key);
    printList(last);  

    return 0;     
}