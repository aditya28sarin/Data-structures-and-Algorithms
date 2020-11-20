#include<bits/stdc++.h>
using namespace std;



//My Implementation

#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int rear, front, size,capacity;
    int* arr;
     
    Queue()
    {
        capacity=0;
    }   
    Queue(int c)
    {
        capacity=c;
        rear=c-1;
        front=0;
        arr= new int[c];
    }
};


int isEmpty(Queue* queue)
{
    return (queue->size==0);
}

int isFull(Queue* queue)
{
    return (queue->size==queue->capacity);
}


void enqueue(Queue* queue, int x)
{

    if(isFull(queue))
        return;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=x;
    queue->size+=1;
}

int dequeue (Queue* queue)
{
    
    if(isEmpty(queue))
        return 0;
     int x = queue->arr[queue->front];
    queue->front= (queue->front+1)%queue->capacity;
   
    queue->size-=1;
    return x;
}

int front (Queue* queue)
{

    if(isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

int rear (Queue* queue)
{
    if(isEmpty(queue))
    return INT_MIN;
    return queue->arr[queue->rear];
}

int main()
{
    Queue* queue=new Queue(1000);

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40); 
  
    cout << "Front item is "
         << front(queue) << endl; 
    cout << "Rear item is "
         << rear(queue) << endl; 
}

//GFG Implementation

// class Queue{
// public:
//     int front, rear, size;
//     unsigned capacity;
//     int* array;


/*


*/

// };


// Queue* createQueue(int capacity)
// {
//     Queue* queue= new Queue(); 
    
//     //capacity of queue
//     queue->capacity=capacity;
    
//     //initializing front iterator
//     queue->front=0;

//     //initializing end iterator
//     queue->rear=capacity-1;

//     //creating array 
//     queue->array=new int[(queue->capacity * sizeof(int))];

//     return queue;
// }

// //to check if queue is full 
// int isFull(Queue* queue)
// {
//     return(queue->size == queue->capacity);
// }

// //to check if the queue is empty
// int isEmpty(Queue* queue)
// {
//     return (queue->size==0);
// }

// //add an item in the queue
// void enqueue(Queue* queue, int x)
// {

//     if(isFull(queue))
//         return;
    
//     queue->rear=(queue->rear+1)%queue->capacity; 
//     queue->array[queue->rear]=x;                           
//     queue->size+=1;                             
    
// }


// int dequeue(Queue* queue)
// {
//     if(isEmpty(queue))
//         return INT_MIN;

//     int x=queue->array[queue->front];
//     queue->front=(queue->front+1)%queue->capacity;
//     queue->size=queue->size-1;

//     return x;
// }

// //returning the fornt element of the queue
// int front (Queue* queue)
// {
//     if(isEmpty(queue))
//         return INT_MIN;
//     return queue->array[queue->front];
// }


// //returning the last/rear element of the queue
// int rear (Queue* queue)
// {
//     if(isEmpty(queue))
//         return INT_MIN;
//     return queue->array[queue->rear];
// }

// int main()
// {

//     Queue* queue = createQueue(1000);

//      enqueue(queue, 10); 
//     enqueue(queue, 20); 
//     enqueue(queue, 30); 
//     enqueue(queue, 40); 
  
//     cout << dequeue(queue) 
//          << " dequeued from queue\n"; 
  
//     cout << "Front item is "
//          << front(queue) << endl; 
//     cout << "Rear item is "
//          << rear(queue) << endl; 

// }



// 3rd Method

// #include<iostream>
 
// using namespace std;
 
// class Queue {
//   private:
//     int front;
//   int rear;
//   int arr[5];
 
//   public:
//     Queue() {
//       front = -1;
//       rear = -1;
//       for (int i = 0; i < 5; i++) {
//         arr[i] = 0;
//       }
//     }
//   bool isEmpty() {
//     if (front == -1 && rear == -1)
//       return true;
//     else
//       return false;
//   }
//   bool isFull() {
//     if (rear == 4)
//       return true;
//     else
//       return false;
//   }
//   void enqueue(int val) {
//     if (isFull()) {
//       cout << "Queue full" << endl;
//       return;
//     } else if (isEmpty()) {
//       rear = 0;
//       front = 0;
//       arr[rear] = val;
//     } else {
//       rear++;
//       arr[rear] = val;
//     }
 
//   }
 
//   int dequeue() {
//     int x = 0;
//     if (isEmpty()) {
//       cout << "Queue is Empty" << endl;
//       return x;
//     } else if (rear == front) {
//       x = arr[rear];
//       rear = -1;
//       front = -1;
//       return x;
//     } else {
//       cout << "front value: " << front << endl;
//       x = arr[front];
//       arr[front] = 0;
//       front++;
//       return x;
//     }
//   }
 
//   int count() {
//     return (rear - front + 1);
//   }
 
//   void display() {
//     cout << "All values in the Queue are - " << endl;
//     for (int i = 0; i < 5; i++) {
//       cout << arr[i] << "  ";
//     }
//   }
 
// };
 
// int main() {
//   Queue q1;
//   int value, option;
 
//   do {
//     cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
//     cout << "1. Enqueue()" << endl;
//     cout << "2. Dequeue()" << endl;
//     cout << "3. isEmpty()" << endl;
//     cout << "4. isFull()" << endl;
//     cout << "5. count()" << endl;
//     cout << "6. display()" << endl;
//     cout << "7. Clear Screen" << endl << endl;
 
//     cin >> option;
 
//     switch (option) {
//     case 0:
//       break;
//     case 1:
//       cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
//       cin >> value;
//       q1.enqueue(value);
//       break;
//     case 2:
//       cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
//       break;
//     case 3:
//       if (q1.isEmpty())
//         cout << "Queue is Empty" << endl;
//       else
//         cout << "Queue is not Empty" << endl;
//       break;
//     case 4:
//       if (q1.isFull())
//         cout << "Queue is Full" << endl;
//       else
//         cout << "Queue is not Full" << endl;
//       break;
//     case 5:
//       cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
//       break;
//     case 6:
//       cout << "Display Function Called - " << endl;
//       q1.display();
//       break;
//     case 7:
//       system("cls");
//       break;
//     default:
//       cout << "Enter Proper Option number " << endl;
//     }
 
//   } while (option != 0);
 
//   return 0;
// }