#include<iostream>
using namespace std;

// Function to find the transition point
int transitionPoint(int arr[], int n) {
    // code here
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(arr[0]==1)
            return 0;
        if(arr[m]==0 && arr[m+1]==1)
            return m+1;
        if(arr[m]==0  &&  arr[m+1]!=1)
            l=m+1;
        if(arr[m]!=0)
            r=m-1;
    }
    return -1;
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

        int val = transitionPoint(arr,n);
        cout<<val<<endl;

    }
}
