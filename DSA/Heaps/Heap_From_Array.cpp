#include<bits/stdc++.h>
using namespace std;


void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

//max heap 
void heapifyMax(int arr[], int n, int i)
{
    int largest=i;
    int l = 2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest=l;

    if(r<n && arr[r]>arr[largest])
        largest=r;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);

        heapifyMax(arr,n,largest);
    }
}


void constructHeapMax(int arr[], int n)
{
    int start_index=n/2-1;

    for(int i=start_index;i>=0;i--)
    {
        heapifyMax(arr,n,i);
    }
}



//min heap 
void heapifyMin(int arr[], int n, int i)
{
    int smallest=i;
    int l = 2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]<arr[smallest])
        smallest=l;

    if(r<n && arr[r]<arr[smallest])
        smallest=r;

    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);

        heapifyMin(arr,n,smallest);
    }
}

void constructHeapMin(int arr[], int n)
{
    int start_index=n/2-1;

    for(int i=start_index;i>=0;i--)
    {
        heapifyMin(arr,n,i);
    }
}

void printHeap(int arr[], int n) 
{ 
    cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main()
{
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  

  cout<<"Max heap:"<<endl<<endl;
    constructHeapMax(arr, n); 
  
    printHeap(arr, n); 


    cout<<"Min Heap"<<endl<<endl;
    constructHeapMin(arr, n); 
  
    printHeap(arr, n); 

}