// Given a sorted array containing only 0s and 1s, find the transition point. 


// Example 1:

// Input:
// N = 5
// arr[] = {0,0,0,1,1}
// Output: 3
// Explanation: index 3 is the transition 
// point where 1 begins.

// Example 2:

// Input:
// N = 4
// arr[] = {0,0,0,0}
// Output: -1
// Explanation: Since, there is no "1",
// the answer is -1.

// Your Task:
// You don't need to read input or print anything. The task is to complete the 
//function transitionPoint() that takes array and N as input parameters and returns the
// 0 based index of the position where "0" ends and "1" begins. If array does not have any 1s,
// return -1. If array does not have any 0s, return 0.


// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

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
