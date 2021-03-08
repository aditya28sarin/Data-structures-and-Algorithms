//method 1

#include<bits/stdc++.h>
using namespace std;

//creating a node class
class Node{
public:
    int data;
    Node* next;

    Node()
    {
        data=0;
        next=NULL;
    }
};


/* Before push */
//               _____________________
//              |                     |
//    *head --> |     Node object     |
//      ^       | [val=1][*next=NULL] |
//      |       |_____________________|
//      |    
//  **head_ref


//If we use : void insertAtBegining(Node** head_ref, int data)
/* After calling push(&head, 2);
 *                    ^

 *                   `&` operator gets the memory address of `head`, 
 *                       which is a pointer.
 */

//               _________________      _____________________
//              |                 |    |                     |
//    *head --> |   Node object   |    |      Node object    |
//      ^       | [val=2] [*next]----->| [val=1][*next=NULL] |
//      |       |_________________|    |_____________________|
//      |    
//  **head_ref



//If we use : Node* insertAtBegining(Node* head, int data)
/* After calling push(&head, 2);
 *                    ^

 *                   `&` operator gets the memory address of `head`, 
 *                       which is a pointer.
 */

//               _________________      _____________________
//              |                 |    |                     |
//              |   Node object   |    |      Node object    |
//              | [val=2] [*next]----->| [val=1][*next=NULL] |
//              |_________________|    |_____________________|
//                                          ^
//                                          |
//                                         head

//hence when we use second implementation we need to return head as we need to rememeber the previous position of it.

void insertAtBegining(Node** head_ref, int data)
{
    Node* new_node=new Node();

    new_node->data=data;

    new_node->next=(*head_ref);

    (*head_ref)=new_node;
}

void insertAtEnd(Node** head_ref, int data)
{
    Node* new_node=new Node();
    Node* prev_node=(*head_ref);
    
    new_node->data=data;

    new_node->next=NULL;

    //if LL is empty, make head as new node
    if((*head_ref)==NULL)
        (*head_ref)=new_node;
    else 
    {
        while(prev_node->next!=NULL)
            prev_node=prev_node->next;
        prev_node->next=new_node;
    }
}

// 0 indexed
void insertAfter(Node** head_ref, int data, int node_no)
{
    int c=0;
    Node* prev_node=(*head_ref);
    Node* new_node =new Node();

    new_node->data=data;

    while(prev_node->next!=NULL)
    {
         if(c==node_no)
             break;
        prev_node=prev_node->next;
        c++;    
    }

    if(prev_node==NULL)
    {
        cout<<"Previous Node cannot be NULL";
        return;
    }

    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

//deleting a node 
void deleteNode(Node** head_ref, int node_no)
{
    int c=0;
    Node* prev_node =(*head_ref);

    //finding previous node of the node to to be deleted 
    while(prev_node->next!=NULL)
    {
         if(c==node_no-1)
             break;
        prev_node=prev_node->next;
        c++;    
    }

     if((*head_ref)==NULL || prev_node==NULL)
        return;
    
    if(node_no==0)
    {
       (*head_ref)=(*head_ref)->next;
       return;
    }

    //node that is next of the deleted node
    Node *next_node=NULL;

    prev_node->next=prev_node->next->next;
}

//sorting linked list using bubble sort 
void sortLinkedList(Node** head_ref)
{
    Node* slow_node =(*head_ref);
    Node* fast_node=NULL;
    int temp;
    while(slow_node->next!=NULL)
    {
        fast_node=(*head_ref);
        while(fast_node->next!=NULL)
        {
            if(fast_node->data>fast_node->next->data)
            {
                temp=fast_node->data;
                fast_node->data=fast_node->next->data;
                fast_node->next->data=temp;
            }   
            fast_node=fast_node->next;
        }
        slow_node=slow_node->next;
    }
}

//swapping two nodes from links and not just data
void swapTwoNodes(Node** head_ref, int x, int y)
{
    
    Node* curr1=(*head_ref);
    Node* prev1=NULL;
    
    
    Node* curr2=(*head_ref);
    Node* prev2=NULL;
  
 
        while(curr1 && curr1->data!=x)
    {
        prev1=curr1;
        curr1=curr1->next;
    } 
    
        while(curr2 && curr2->data!=y)
    {
        prev2=curr2;
        curr2=curr2->next;
    }
   
    prev1->next=curr2;
    prev2->next=curr1;
    
    Node* temp = curr1->next;
    curr1->next=curr2->next;
    curr2->next=temp;
    
}

//reverse Linked List
void reverseList(Node** head_ref)
{
    Node* curr_node=(*head_ref);
    Node* prev_node=NULL;
    Node* next_node = NULL;

    while(curr_node!=NULL)
    {
        next_node=curr_node->next;
        curr_node->next=prev_node;
        prev_node=curr_node;
        curr_node=next_node;
    }
    
    (*head_ref)=prev_node;
}

//recursive reverse
Node* recursiveReverseList(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node* temp=recursiveReverseList(head->next);
    
    head->next->next=head;
    head->next=NULL;

    return head;
}



Node* intersectionOfLL(Node* head1, Node* head2)
{
    Node* head3= new Node();
    Node* temp1=head1;
    Node* temp2=head2;
    Node* temp3=head3;

    while ( temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            insertAtEnd((&temp3->next),temp1->data);
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        
        else if(temp1->data<temp2->data)
        {
            temp1=temp1->next;
        }
        else if (temp2->data<temp1->data)
        {
            temp2=temp2->next;
        }
    }
    return head3->next;
}


// Node* Reverse(Node* head)
// {

//     Node* currPtr=head;
//     Node* prevPtr=NULL;
//     Node* nextPtr=head;


//     while(currPtr!=NULL)
//     {
//         nextPtr=currPtr->next;
//         currPtr->next=prevPtr;
//         prevPtr=currPtr;
//         currPtr=nextPtr;
//     }
//     head=prevPtr;

//     return head;
// }

int GetNth(Node* head, int index){
  int temp=0;
  Node* ptr=head;
  int count =0;
  while(ptr!=NULL)
  {
      count++;
      if(count==index)
      {
          temp=ptr->data;
      }
      ptr=ptr->next;
  }
  return temp;
}


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


bool search(Node* head,int key)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        if(temp->data==key)
            return true;
        temp=temp->next;
    }
    return false;
}


void printList(Node** head_ref)
{
    Node* new_node=(*head_ref);

    while(new_node!=NULL)
    {
        cout<<new_node->data<<"-->";
        new_node=new_node->next;
    }
    cout<<"NULL";
    cout<<endl;
}



int main()
{
    Node* head1=new Node();

    head1=NULL;

    insertAtEnd(&head1,5);
     printList(&head1);
    insertAtEnd(&head1,10);
     printList(&head1);  
    insertAtEnd(&head1,15);
     printList(&head1);  
    insertAtEnd(&head1,20);
     printList(&head1);

    cout<<GetNth(head1,2)<<endl;

    search(head1, 15)? cout<<"Yes"<<endl : cout<<"No"<<endl;  

    cout<<getNthFromLast(head1,3)<<endl;

    head1=Reverse(head1);

    printList(&head1);
    
    Node* head2=new Node();

    head2=NULL;
   
     insertAtEnd(&head2,2);
     printList(&head2);  
     insertAtEnd(&head2,2);
     printList(&head2);
     
     insertAtEnd(&head2,20);
     printList(&head2);  
     insertAtEnd(&head2,19);
     printList(&head2);  


    swapTwoNodes(&head1,20,14);
    cout<<"After Swapping"<<endl;
     printList(&head1);
    cout<<"Sorted List"<<endl;
    sortLinkedList(&head1);
    printList(&head1);


    insertAtEnd(&head1,2); 
    printList(&head1);
    insertAfter(&head1,5,1);
    printList(&head1);

   // deleteNode(&head,1);
   sortLinkedList(&head1);
    printList(&head1);

    reverseList(&head1);
    printList(&head1);
    head1=recursiveReverseList(head1);
    printList(&head1);
     
    Node* head3=new Node();

    head3=NULL;

    head3=intersectionOfLL(head1,head2);
    printList(&head3);

}
