#include<bits/stdc++.h>
using namespace std;


int binarySearch(int l, int r, int arr[], int element)
{
    if(l<=r)
    {
    
        int m = l+(r-l)/2;
    
        if(arr[m]==element)
            return m;
    
        if(arr[m]>=element && arr[m]>arr[m-1] && arr[m]<arr[m+1])
            return binarySearch(l,m-1,arr,element);
            
        if(arr[m]<=element && arr[m]>arr[m-1] && arr[m]<arr[m+1])
            return binarySearch(m+1,r,arr,element);
            
        if(arr[m]>=element && arr[m]>arr[m-1] && arr[m]>arr[m+1])
            return binarySearch(m+1,r,arr,element);
    }
    return -1;
}

int main()
{
    int size;
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int element;
    cin>>element;

    cout<<binarySearch(0,size-1,arr,element);
}