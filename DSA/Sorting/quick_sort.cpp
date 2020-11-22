#include <bits/stdc++.h> 
using namespace std;  
  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  


int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int pIndex=low;

    for(int i=low;i<=high-1;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex],&arr[high]);

    return pIndex;
}


void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int index = partition(arr,low,high);

        quickSort(arr,low,index-1);
        quickSort(arr,index+1,high);
    }
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
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout <<"Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  