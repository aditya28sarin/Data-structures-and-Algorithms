#include<bits/stdc++.h>
using namespace std;


void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

class MinHeap
{
    int capacity;
    int size;
    int *arr;

    public:
        
        MinHeap(int c);
        
        int parent(int i)
        {
            return ((i-1)/2);
        }

        int left(int i)
        {
            return (2*i+1);
        } 

        int right (int i)
        {
            return (2*i+2);
        }

        void insertKey(int k);

        int getMin();

        void decreaseKey(int , int);

        void heapify(int );

        int extractMin();

        void deleteKey(int );
};


MinHeap::MinHeap(int c)
{
    size=0;
    capacity=c;
    arr=new int[c];
}

void MinHeap::insertKey(int k)
{
    if(size==capacity)
        cout<<"Heap is full!"<<endl;
    
    size++;
    arr[size-1]=k;
    int i = size-1;

    while(i!=0 && arr[parent(i)]> arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }
}


int MinHeap::getMin()
{
    return arr[0];
}


void MinHeap::decreaseKey(int i, int k)
{
    arr[i]=k;

    while(i!=0 && arr[parent(i)]> arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }
}

void MinHeap::heapify(int i)
{
    int l =left(i);
    int r=right(i);
    int smallest=i;

    if(l<size && arr[l]<arr[smallest])
        smallest=l;

    if(r<size && arr[r]<arr[smallest])
        smallest=r;

    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        heapify(smallest);
    }
}

int MinHeap::extractMin()
{
    if(size<=0)
        return -1;
    if(size==1)
    {
        size--;
        return arr[0];
    }

    int root=arr[0];
    arr[0]=arr[size-1];
    size--;

    heapify(0);

    return root;
}


void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// void swap(int *a, int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }

// class MinHeap{
// int *harr;
// int capacity;
// int heap_size;
// public:
//     //constructor
//     MinHeap(int capacity);

//     // to heapify a subtree with the root at given index
//     void minHeapify(int);

//     //get the index of parent 
//     int parent(int i)
//     {
//         return ((i-1)/2);
//     }

//     //get the index of left child 
//     int left(int i)
//     {
//         return (2*i+1);       
//     }

//     //get the index of right child 
//     int right(int i)
//     {
//         return (2*i+2);
//     }

//     //method to extract min element 
//     int getMin();

//     //decrease key value of index from i to new_val
//     void decreaseKey(int i, int new_val);

//     //returns the minimum element from min heap 
//     int extractMin();

//     //deletes a node stored at i
//     void deleteKey(int i);

//     //insert an new key 'k'
//     void insertKey(int k);
// };

// // Constructor: Builds a heap from a given array a[] of given size 
// MinHeap :: MinHeap(int cap)
// {
//     heap_size=0;
//     capacity=cap;
//     harr=new int[cap];
// }


// void MinHeap :: insertKey(int k)
// {
//     if(heap_size==capacity)
//     {
//         cout<<"Cannot insert here, heap is full!"<<endl;
//     }

//     heap_size=heap_size+1;
//     int i = heap_size-1;
//     harr[i]=k;

//     //check for violation of heap property
//     while(i!=0 && harr[parent(i)]>harr[i])
//     {
//         swap(&harr[parent(i)], &harr[i]);
//         i=parent(i);
//     } 
// }

// void MinHeap :: decreaseKey(int i, int new_val)
// {
//     harr[i]=new_val;

//     while(i!=0 && harr[parent(i)]>harr[i])
//     {
//         swap(&harr[parent(i)], &harr[i]);
//         i=parent(i);  
//     }
// }

// int MinHeap :: getMin()
// {
//     return harr[0];
// }


// void MinHeap :: minHeapify(int i)
// {
//     int l = left(i);
//     int r = right(i);
//     int smallest=i;

//     if(l<heap_size && harr[l]<harr[i])
//         smallest=l;
//     if(r<heap_size && harr[r]<harr[smallest])
//         smallest=r;

//     if(smallest!=i)
//     {
//         swap(&harr[smallest],&harr[i]);
//         minHeapify(smallest);
//     }

// }

// int MinHeap :: extractMin()
// {
//     if(heap_size<=0)
//         return INT_MAX;
//     if(heap_size==1)
//     {
//         heap_size--;
//         return harr[0];
//     }

//     int root=harr[0];
//     harr[0]=harr[heap_size-1];
//     heap_size--;
//     minHeapify(0);

//     return root;
// }


// void MinHeap :: deleteKey(int i)
// {
//     decreaseKey(i,INT_MIN);
//     extractMin();
// }


int main()
{
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
}