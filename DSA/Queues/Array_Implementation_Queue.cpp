#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int front,rear,size;
    unsigned capacity;
    int *arr;
};

Queue* createQueue(unsigned capacity){
    
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->size=0;
    queue->front=0;
    queue->arr = new int[queue->capacity*sizeof(int)];
}

int isFull(Queue* queue){
    return(queue->size == queue-> capacity);
}

int isEmpty(Queue* queue){
    return (queue->size==0);
}

void enqueue(Queue* queue, int data){
    
    if(isFull(queue))
        return;
     
    queue->rear = (queue->rear + 1) % (queue->capacity);
    queue->arr[queue->rear]=data;
    queue->size = queue->size+1;
    
    cout << data << " enqueued to queue\n"; 
}

int dequeue(Queue* queue){
     if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->arr[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
}

int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->arr[queue->front]; 
} 
  
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->arr[queue->rear]; 
} 


int main() 
{ 
    Queue* queue = createQueue(1000); 
  
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    cout << dequeue(queue) 
         << " dequeued from queue\n"; 
  
    cout << "Front item is "
         << front(queue) << endl; 
    cout << "Rear item is "
         << rear(queue) << endl; 
  
    return 0; 
} 