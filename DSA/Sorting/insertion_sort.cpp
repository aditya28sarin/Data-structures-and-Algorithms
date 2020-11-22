#include<iostream>
using namespace std;


///My try for Insertion sort
/* The task is to complete insert() which is used
   as shown below to implement insertionSort() */
/* Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++)
      insert(arr, i);
} */

//void insert(int arr[], int i)
//{
//        int j=i;
//        while(arr[i]<arr[j-1])
//        {
//             if(j==0)
//        {
//            break;
//        }
//            int temp=arr[j-1];
//            arr[j-1]=arr[i];
//            arr[i]=temp;
//            i--;
//            j--;
//
//        }
//}


void insertionSort(int arr[],int n)
{
    for (int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n;
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        insertionSort(arr,n);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}


//recursive

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
 
