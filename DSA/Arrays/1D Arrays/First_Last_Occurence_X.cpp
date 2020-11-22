// Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

// Note: If the number x is not found in the array just print '-1'.

// Input:
// The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

// Output:
// Print index of the first and last occurrences of the number x with a space in between.

// Constraints: 
// 1<=T<=100
// 1<=n,a[i]<=1000

// Example:
// Input:
// 2
// 9 5
// 1 3 5 5 5 5 67 123 125
// 9 7
// 1 3 5 5 5 5 7 123 125

// Output:
// 2 5
// 6 6



-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;


void binarySearch(int arr[], int l, int r,int x)
{
    if(l<=r)
    {
        int mid = l +(r-l)/2;
        
        if(arr[mid]==x && arr[mid-1]!=x)
        {
            int li=mid;
            while(arr[mid]==x)
            {
                mid++;
            }
            int ri=mid-1;
            
            cout<<li<<" "<<ri;
            return;
        }
        
        if(arr[mid]!=x && arr[mid]<x)
            binarySearch(arr,mid+1,r,x);
        
        if((arr[mid]!=x && arr[mid]>x) || (arr[mid]==x && arr[mid-1]==x))
            binarySearch(arr,l,mid-1,x);
            
    }
    else
     cout<<-1;
}





int main() {
	int cases;
	
	cin>>cases;
	
	while(cases--)
	{
	    int n,x;
	    
	    cin>>n>>x;
	    
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	   binarySearch(arr,0,n-1,x);
	   
	    cout<<endl;
	}
	
	return 0;
}