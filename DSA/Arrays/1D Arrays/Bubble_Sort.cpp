#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {   int flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }   
}

//recursive bubble sort 
void recursiveBubbleSort(int arr[], int size)
{
    if(size<=1)
        return;
    
    for(int i=0; i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp =arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }

    recursiveBubbleSort(arr,size-1);
}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
int main()  
{  
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    printArray(arr, n);  

    recursiveBubbleSort(arr, n);  
    cout<<"\n\nSorted array with Recursive Bubble Sort: \n";  
    printArray(arr, n);  
    return 0;  
}  
  