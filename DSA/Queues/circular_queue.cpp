#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
public:
    int rear,front;
    int size;
    int *arr;
    
    CircularQueue(int s){
        front=rear=-1;
        size=s;
        arr = new int[s];
    }
    
    
    void enqueue(int data);
    int dequeue();
    void displayQueue();
};


void CircularQueue :: enqueue(int data){
    
    if((rear==size-1 && front == 0) || rear == (front-1) % (size-1)){
        cout<<"Circular Queue is full"<<endl;
        return;
    }
    
    //to insert the first element 
    else if(front==-1){
        rear=front=0;
        arr[rear]=data;
    }
    
    //if the queue is empty from forward but full from behind
    else if (rear==size-1 && front!=0){
        rear=0;
        arr[rear]=data;
    }
    //normal element entry
    else{
        rear++;
        arr[rear]=data;
    }
}


int CircularQueue :: dequeue(){
    
    if(front==-1){
        cout<<"The queue is empty!"<<endl;
        return INT_MIN;
    }
    
    int data = arr[front];
    arr[front]=-1;
    
    if(front==rear){
        front=rear=-1;
    }
    else if(front=size-1){
        front=0;
    }
    else{
        front++;
    }
    
    return data;
}


void CircularQueue::displayQueue() 
{ 
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", arr[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", arr[i]); 
    } 
} 
  
/* Driver of the program */
int main() 
{ 
    CircularQueue q(5); 
  
    // Inserting elements in Circular Queue 
    q.enqueue(14); 
    q.enqueue(22); 
    q.enqueue(13); 
    q.enqueue(-6); 
  
    // Display elements present in Circular Queue 
    q.displayQueue(); 
  
    // Deleting elements from Circular Queue 
    printf("\nDeleted value = %d", q.dequeue()); 
    printf("\nDeleted value = %d", q.dequeue()); 
  
    q.displayQueue(); 
  
    q.enqueue(9); 
    q.enqueue(20); 
    q.enqueue(5); 
  
    q.displayQueue(); 
  
    q.enqueue(20); 
    return 0; 
} 