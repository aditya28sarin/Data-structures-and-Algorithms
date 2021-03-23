//Given two arrays A and B of size N and M respectively. 
// The task is to find union between these two arrays.
//Union of the two arrays can be defined as the set containing distinct elements from 
// both the arrays. If there are repetitions, then only one occurrence of element should be
 // printed in union.

// Input:
// The first line of input contains an integer T denoting the number of test cases.
// Then T test cases follow. Each test case consist of three lines. The first line of each test 
// case contains two space separated integers N and M, where N is the size of array A and M is 
// the size of array B. The second line of each test case contains N space separated integers
 // denoting elements of array A. The third line of each test case contains M space separated 
 // integers denoting elements of array B.

// Output:
// Correspoding to each test case, print the count of union elements of the two arrays.

// Expected Time Complexity: O(N + M).
// Expected Auxiliary Space: O(N + M).

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ N, M ≤ 105
// 1 ≤ A[i], B[i] < 105

// Example:
// Input:
// 2
// 5 3
// 1 2 3 4 5
// 1 2 3
// 6 2
// 85 25 1 32 54 6
// 85 2
// Output:
// 5
// 7

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


//method 1

#include <bits/stdc++.h> 
using namespace std; 

int printUnion(int arr1[], int arr2[], int m, int n) 
{ 
	int i = 0, j = 0; 
	while (i < m && j < n) { 
		if (arr1[i] < arr2[j]) 
			cout << arr1[i++] << " "; 

		else if (arr2[j] < arr1[i]) 
			cout << arr2[j++] << " "; 

		else { 
			cout << arr2[j++] << " "; 
			i++; 
		} 
	} 

	while (i < m) 
		cout << arr1[i++] << " "; 

	while (j < n) 
		cout << arr2[j++] << " "; 
} 
int main() 
{ 
	int arr1[] = { 1, 2, 4, 5, 6 }; 
	int arr2[] = { 2, 3, 5, 7 }; 

	int m = sizeof(arr1) / sizeof(arr1[0]); 
	int n = sizeof(arr2) / sizeof(arr2[0]); 

	// Function calling 
	printUnion(arr1, arr2, m, n); 

	return 0; 
} 



//method 2

#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int l, int r, int key)
{

    while(r>=l)
    {
        int m=l+(r-l)/2;

        if(key==arr[m])
            return m;
        if(key>arr[m])
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}


void printUnion(int arr1[], int arr2[], int m, int n)
{

    if (m < n)
  {
    int p=0;
    sort(arr1, arr1 + m);
     for (int i=0; i<m; i++)
        {
            if(arr2[i]!=arr2[i+1])
                p++;
        }
    int cp=0;
    for (int i=0; i<n; i++)
        if (binarySearch(arr1, 0, m-1, arr2[i]) == -1)
            //cout << arr2[i] << " ";
            cp++;
    cout<<cp+p<<endl;
  }
  else{
    {
    int p=0;
    sort(arr2, arr2 + n);
     for (int i=0; i<n; i++)
        {
            if(arr1[i]!=arr1[i+1])
                p++;
        }
    int cp=0;
    for (int i=0; i<m; i++)
        if (binarySearch(arr2, 0, n-1, arr1[i]) == -1)
            //cout << arr2[i] << " ";
            cp++;
    cout<<cp+p<<endl;
  }
  }
}

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n1,n2;
        cin>>n1>>n2;
        int p1=0,p2=0;
     int arr1[n1],arr2[n2];

        for(int i=0;i<n1;i++)
        {
            cin>>arr1[i];
        }

        for(int i=0;i<n2;i++)
        {
            cin>>arr2[i];
        }

       printUnion(arr1,arr2,n1,n2);

    }
}


