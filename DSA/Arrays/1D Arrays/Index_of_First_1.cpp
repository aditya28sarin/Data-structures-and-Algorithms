// Given a sorted array consisting 0’s and 1’s. The task is to find the index of first ‘1’ in the 
//given array.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test
// cases follow. Each test case consists of two lines. First line of each test case contains an 
//Integer N denoting size of array and the second line contains N space separated 0 and 1.

// Output:
// For each test case, in a new line print the index of first 1. If 1 is not present in the array
// then print “-1”.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 107
// 0 <= Ai <= 1018

// Example:
// Input:
// 2
// 10
// 0 0 0 0 0 0 1 1 1 1
// 4
// 0 0 0 0

// Output:
// 6
// -1


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;


int main() {
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
	    int flag=0,index=0;
	    for(int j=0;j<n;j++)
	    {
	        if(arr[j]==1)
	        {
	           flag=1;
	           index=j;
	           break;
	        }
	    }
	    
	    if(flag==1)
	    {
	        cout<<index<<endl;
	    }
	    else
	    {
	        cout<<-1<<endl;
	    }
    }
    
}
