#include<bits/stdc++.h>
using namespace std;


void sortedArr(int start, int end, int *arr)
{
    
    while(start<=end)
    {
        if(arr[start]<0 && arr[end]<0)
            start++;
        
        if(arr[start]>0 && arr[end]>0)
            end--;
        
        if((arr[start]>0 && arr[end]<0) || (arr[start]<0 && arr[end]>0))
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    
}

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int size;
        cin>>size;

        int arr[size];
        
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }

        sortedArr(0,size-1,arr);

        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}