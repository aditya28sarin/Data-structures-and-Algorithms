#include<bits/stdc++.h>
using namespace std;


class Node{
public: 
    int data;
    Node* next;

    Node(){
        data=0;
        next=NULL;
    }
};

//insert at begining
void insertAtBegining(Node** head_ref, int data){
    
    
    Node* new_node = new Node();
    
    new_node->data =data;
    
    new_node->next = (*head_ref);
    
    (*head_ref)=new_node;
    
}

//isnerting node at the end
void insertAtEnd(Node** head_ref, int data){
    Node* new_node = new Node();
    new_node->data=data;
    
    Node* temp= (*head_ref);
    
    
    if((*head_ref)==NULL){
        (*head_ref)=new_node;
        return;
    }
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next=new_node;
}


// insert node after a certain node
void insertAfter(Node** head_ref, int data, int node_no){
    
    
    Node* new_node = new Node();
    new_node->data=data;
    Node* temp = (*head_ref);

    
    while(node_no--){
        
        if(node_no==0){
            break;
        }
        
        temp=temp->next;
    }
    
    if(temp==NULL){
     cout<<"Previous node cannot be NULL";
     return;
    }

    Node* next_ptr=temp->next;
    temp->next=new_node;
    new_node->next=next_ptr;
}

//Delete Node
void deleteNode(Node** head_ref, int node_no){
    
    Node* temp = (*head_ref);
    
    while(node_no-- > 2){
        temp=temp->next;    
    }
    
    //if list is empty of the node to be deleted is not there
    if((*head_ref)==NULL || temp == NULL){
        return;
    }
    
    //if the node tot be deleted is the first node
    if(node_no==0){
        (*head_ref)==(*head_ref)->next;
        return;
    }
    
    
    temp->next = temp->next->next;
    
}


//print linked list
void printList(Node** head_ref){
    
    Node* temp = (*head_ref);
    
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}


int main(){
    
    Node* head1 = new Node();
    
    head1=NULL;
    
    insertAtBegining(&head1,20);
    printList(&head1);
    
    insertAtBegining(&head1,10);
    printList(&head1);
    
    insertAtEnd(&head1,30);
    printList(&head1);
    
    insertAtEnd(&head1,40);
    printList(&head1);
    
    insertAtEnd(&head1,50);
    printList(&head1);
    
    insertAfter(&head1,25,2);
     printList(&head1);
     
    deleteNode(&head1,2);
    printList(&head1);
}