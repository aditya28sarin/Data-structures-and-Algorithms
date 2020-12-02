#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest = i;
	
	if(l<n && arr[l]>arr[i])
	{
		largest=l;
	}
	
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	
	if(largest!=i)
	{
		swap(arr[largest], arr[i]);
		maxHeapify(arr,n,largest);
	}
}


void buildHeap(int arr[], int n)
{
	int index = (n/2)-1;
	
	for(int i=index ;i>=0;i--)
	{
		maxHeapify(arr,n,i);
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
  
    buildHeap(arr, n); 
  
    printHeap(arr, n); 
  
    return 0; 
} 