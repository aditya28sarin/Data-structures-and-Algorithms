#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

//iterative algorithm
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
            int j=i-1;
            while(arr[j]>arr[j+1] && j>=0)
            {
                swap(arr[j],arr[j+1]);
                j--;
            }
    }
}


//recrusive algorithm 
void insertSortRecursive(int arr[], int n)
{
    if(n<=1)
        return;

    insertSortRecursive(arr,n-1);
    int j=n-1;

    while(arr[j+1]<arr[j] && j>=0)
    {
        swap(arr[j],arr[j+1]);
        j--;
    }

}


void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  

int main()
{
    int arr[] = { 110, 78, 13, 1, 14 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    // insertionSort(arr, n);  
    // printArray(arr, n); 


    insertSortRecursive(arr, n);  
    printArray(arr, n);  
  
    return 0;  
}