#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int data)
{
    Node* new_node=new Node();
    new_node->data=data;

    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void pop(Node** head_ref)
{
    Node* new_node=new Node();

    if((*head_ref)==NULL)
    {
        (*head_ref)=new_node;
    }
    else
    {
        new_node=(*head_ref);
        (*head_ref)=(*head_ref)->next;
    }
}


void reverse(Node** head_ref)
{
    Node* curr=(*head_ref);
    Node* prev=NULL;
    Node* after=NULL;

    while(curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    (*head_ref)=prev;
}


int isEmpty(Node** head_ref)
{
    return (*head_ref)==NULL;
}


int isTop(Node** head_ref)
{
        return (*head_ref)->data;
}


int main()
{
    Node* head=NULL;
    
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);

    pop(&head);

    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    reverse(&head);
    
    cout<<endl;
    
    Node* temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}



































// #include<bits/stdc++.h>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;
// };

// Node* head;

// void push(int data)
// {
//     Node* temp =new Node();
    
//     if(!temp)
//     {
//         cout<<"Stack Overflow"<<endl;
//         exit(1);
//     }
//     temp->data=data;
//     temp->next=head;
//     head=temp;
    
    
// }

// void pop()
// {
//     Node* temp;

//     if(head==NULL)
//     {
//         cout<<"Stack Underflow"<<endl;
//         exit(1);
//     }
//     else
//     {   temp=head;
//         head=head->next;
//         temp->next=NULL;
//         free(temp);
//     }
// }

// int isEmpty()
// {
//     if(head==NULL)
//         return 1;
//     else
//         return 0;
        
// }

// int top()
// {
//     if(!isEmpty())
//     {
//         return head->data;
//     }
//     else
//     {
//         exit(1);
//     }
    
// }

//     void reverse()
//     {
//         Node* prev= NULL;
//         Node* curr=head;
//         Node* after=NULL;

//         while(curr!=NULL)
//         {
//             after=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=after;
//         }
//         head=prev;
//     }

//     void display()
//     {
//         if(head==NULL)
//         {
//             cout<<"Stack Underflow"<<endl;
//             exit(1);
//         }
//         else
//         {
//            Node* temp=head;
//             while(temp!=NULL)
//             {
//                 cout<<temp->data<<" ";
//                 temp=temp->next;
//             }
//         }
        
//     }

// int main()
// {
//     push(11); 
//     push(22); 
//     push(33); 
//     push(44); 
  
//     // display stack elements 
//     display(); 

//     cout<<endl;

//     reverse(); 
  
//     cout << "Reversed Stack" << endl; 
//     display(); 
      
//     return 0; 

    
// }