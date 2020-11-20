#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp;
    temp=a;a=b;
    b=temp;
}

void selectionSort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=arr[i],min_index;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<=temp)
            {
                temp=arr[j];
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

//recursive solution
void recursiveSelectionSort(int arr[], int n, int start)
{
    if(start==n-1)
        return;

    int temp = arr[start];
    int min_index;
    for(int i=start;i<n;i++)
    {
        if(arr[i]<=temp)
        {
            temp=arr[i];
            min_index=i;
        }
    }
    swap(arr[start],arr[min_index]);

    recursiveSelectionSort(arr,n,start+1);
}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
int main()  
{  
    int arr[] = {64, 59, 9, 20, 2};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  


    recursiveSelectionSort(arr,n,0);
    cout << "\n\nSorted array with Recursive Solution: \n";  
    printArray(arr, n); 
    return 0;  
}  
