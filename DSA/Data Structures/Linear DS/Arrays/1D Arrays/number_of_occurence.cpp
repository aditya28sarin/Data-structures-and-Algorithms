#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int binarySearch(int arr[], int l, int r, int x)
{
    while(l<=r)
    {
        int m=l+(r-1)/2;
        if(arr[m]==x)
            return m;
        if(arr[m]<x)
            l=m+1;
        else
            r=m-1;
    }
    return -1;;
}

void sorting_array(int arr[], int n)
{
    int temp=arr[0];
    for (int i=0;i<n-1;i++)
    {
        if(arr[i]>=arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}
int func_freq(int arr[], int n, int k)
{
    int index =binarySearch(arr,0,n-1,k);
    int count =1;
    int left=index-1;
    while(left>=0 &&  arr[left]==k)
        count++,left--;
    int right= index+1;
    while(right<n && arr[right]==k)
        count++,right++;
    return count;
}
int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {

        int n,k;
        cin>>n>>k;
        int arr[n],val;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        sorting_array(arr,n);
        val=func_freq(arr,n,k);
        cout<<val<<endl;
}
}

///method 2
//
//int counting_number(int arr[], int x, int n)
//{
//
//    int *low=lower_bound(arr,arr+n,x);
//
//
//     if (low == (arr + n) || *low != x)
//     return 0;
//
//     int *high=upper_bound(low,arr+n,x);
//
//     return high - low;
//}
//
//int main()
//{
//    int cases;
//    cin>>cases;
//
//    while(cases--)
//    {
//
//        int n,k;
//        cin>>n>>k;
//        int arr[n],val;
//
//        for(int i=0;i<n;i++)
//        {
//            cin>>arr[i];
//        }
//
//        val=counting_number(arr,k,n);
//
//        cout<<val<<endl;
//}
//}
