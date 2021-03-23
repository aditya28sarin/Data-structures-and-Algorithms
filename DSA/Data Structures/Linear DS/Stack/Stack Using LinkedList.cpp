#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

    void push(Node** head, int d)
    {
        Node* new_node=new Node();
        new_node->data=d;

        new_node->next=(*head);
        (*head)=new_node;
           cout << d<< " pushed to stack\n"; 
    }

     int pop(Node** head)
    {
        Node* ptr=(*head);
        
        (*head)=(*head)->next;
    
        int popped=ptr->data;
        return popped;
    }



int main()
{
    Node* head=NULL;
    push(&head, 10); 
    push(&head, 20); 
    push(&head, 30); 
  
    cout << pop(&head) <<"popped from stack\n"; 
  
    return 0; 

}