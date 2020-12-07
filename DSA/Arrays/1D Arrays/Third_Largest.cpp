// Given an array of distinct elements. Find the third largest element in it. 

// Example 1:

// Input:
// N = 5
// A[] = {2,4,1,3,5}
// Output: 3
// Example 2:

// Input:
// N = 2
// A[] = {10,2}
// Output: -1
// Your Task:
// Complete the function thirdLargest() which takes the array a[] and the size of the array, 
//n, as input parameters and returns the third largest element in the array. It return -1 if 
//there are less than 3 elements in the given array.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[i] ≤ 105

// -------------------------------------------------------------------------------------------------------
// 						CODE
// -------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
int thirdLargest(int a[],int n);
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<thirdLargest(a,n)<<endl;
    }
}

int thirdLargest(int a[], int n)
{
    int first=a[0];
    int second=INT_MIN;
    int third=INT_MIN;

    for(int i=1;i<n;i++)
    {
        if(a[i]>first)
        {
            third=second;
            second=first;
            first=a[i];
        }
        else if(a[i]>second)
        {
            third=second;
            second=a[i];
        }
        else if(a[i]>third)
            third=a[i];
    }

    return third;
}
