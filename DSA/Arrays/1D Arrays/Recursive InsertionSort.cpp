#include<iostream>
using namespace std;




void insertionSortRecursive(int arr[],int n)
{

    if(n<=1)
        return;
    else
    {
        insertionSortRecursive(arr,n-1);
    }


}



// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout << arr[i] <<" ";
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSortRecursive(arr, n);
    printArray(arr, n);

    return 0;
}
