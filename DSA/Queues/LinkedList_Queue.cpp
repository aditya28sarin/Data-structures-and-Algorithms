#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear=NULL;

void enqueue(int x)
{
    Node* new_node = new Node();
    new_node -> data = x;
    new_node -> next =NULL;

    if(rear==NULL && front==NULL)
    {
        rear=front=new_node;
        return;
    }

    rear->next=new_node;
    rear=new_node;
}


void dequeue()
{
    Node* new_node=front;

    if(front==NULL)
    {
    cout<<"Queue is empty";
    return;
    }
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    free(new_node);

}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return 0;
	}
	return front->data;
}

void Print() {
	struct Node* new_node = front;
	while(new_node != NULL) {
		printf("%d ",new_node->data);
		new_node = new_node->next;
	}
	printf("\n");
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	enqueue(2); Print(); 
	enqueue(4); Print();
	enqueue(6); Print();
	dequeue();  Print();
	enqueue(8); Print();
}