#include<bits/stdc++.h> 
using namespace std; 
 
class Node 
{ 
public:
    int data; 
    Node *next, *prev; 
}; 

void insert( Node **head, int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->next = temp->prev = NULL; 
    if (!(*head)) 
        (*head) = temp; 
    else
    { 
        temp->next = *head; 
        (*head)->prev = temp; 
        (*head) = temp; 
    } 
} 
 

void findPairSumDLL(Node* head, int x)
{
	Node* first = head;
	Node* last = head;

	while(last->next!=NULL)
	{
		last=last->next;
	}

	while(first!=NULL && last!=NULL && first -> next != last && first!=last)
	{
		if(first->data + last->data < x)
		{
			first=first->next;
		}

		if(first->data + last->data > x)
		{
			last=last->prev;
		}
		else
		{
			 cout << "(" << first->data<< ", "
                << last->data << ")" << endl; 

                first=first->next;
                last=last->prev;
		}
		
	}
}

int main() 
{ 
    struct Node *head = NULL; 
    insert(&head, 9); 
    insert(&head, 8); 
    insert(&head, 6); 
    insert(&head, 5); 
    insert(&head, 4); 
    insert(&head, 2); 
    insert(&head, 1); 
    int x = 7; 
 
    findPairSumDLL(head, x); 
 
    return 0; 
} 