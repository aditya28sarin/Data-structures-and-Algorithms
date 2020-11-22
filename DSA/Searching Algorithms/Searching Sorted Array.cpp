#include<iostream>
using namespace std;


///Method 2: Original Iterative Approach

//int binarySearch(int arr[], int l, int r, int x)
//{
//
//    while(l<=r)
//    {
//
//        int m=l+(r-1)/2;
//
//        if(arr[m]==x)
//            return 1;
//
//        if(arr[m]<x)
//            l=m+1;
//        else
//            r=m-1;
//    }
//    return -1;
//}
//
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
//        val=binarySearch(arr,0,n-1,k);
//        cout<<val<<endl;
//
//
//
//}
//}

///Method 3: Original Recursive approach
int recursiveBinarySearch(int arr[], int l,int r, int x);
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

        val=recursiveBinarySearch(arr,0,n-1,k);
        cout<<val<<endl;
    }
}

int recursiveBinarySearch(int arr[], int l,int r, int x)
{
    while(r>=l)
    {
    int m=l+(r-l)/2;

    if(arr[m]==x)
        return 1;

    if(x<arr[m])
    {

        recursiveBinarySearch(arr, l, m-1,x);
    }
    else
        {

            recursiveBinarySearch(arr,m+1,r,x);
        }
    }

    return -1;
}


