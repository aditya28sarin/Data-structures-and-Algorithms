// Given an array of integers, print the array in such a way that the first element is first maximum and second element is first minimum and so on.

// Examples :

// Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
// Output : 7 1 6 2 5 3 4

// Input : arr[] = {1, 6, 9, 4, 3, 7, 8, 2}
// Output : 9 1 8 2 7 3 6 4


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
using namespace std;

///my approach O(n^2)
void selectionSort(int arr[], int n)
{
   int max_index,min_index;

   for(int i=0;i<n-1;i++)
   {
       max_index=i;
       min_index=i;
       for(int j=i+1;j<n;j++)
       {
           if(i%2==0)
           {
               if(arr[j]>arr[max_index])
               {
                   max_index=j;
               }
           }
           else
           {
               if(arr[j]<arr[min_index])
               {
                   min_index=j;
               }
           }
       }
       if(i%2==0)
       {
           int temp=arr[i];
           arr[i]=arr[max_index];
           arr[max_index]=temp;
       }
       else
       {
           int temp=arr[i];
           arr[i]=arr[min_index];
           arr[min_index]=temp;
       }
   }
}


//efficient algorithm O(nlogn)
void alternateSort(int arr[], int n)
{
    sort(arr,arr+n);

    int i=0,j=n-1;
    while(i<j)
    {
        cout<<arr[j--]<<" ";
        cout<<arr[i++]<<" ";
    }
    if(n%2!=0)
    {
        cout<<arr[i];
    }
}

int main()
{
    int no_of_cases;
    cin>>no_of_cases;
    while(no_of_cases--)
    {
        int size_of_array;
        cin>>size_of_aaray;
        int arr[size_of_aaray];
        for(int i=0;i<size_of_aaray;i++)
        {
            cin>>arr[i];
        }
        alternateSort(arr,n);

//        selectionSortFunc(arr,n);
//        for(int i=0;i<n;i++)
//        {
//            cout<<arr[i]<<" ";
//        }
    }
}
