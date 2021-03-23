// Given an array arr[] and a position in array, k. Write a function name reverse (a[], k) such that it reverses subarray arr[0..k-1]. Extra space used should be O(1) and time complexity should be O(k).
// Example:

// Input:
// arr[] = {1, 2, 3, 4, 5, 6}
    // k = 4

// Output:
// arr[] = {4, 3, 2, 1, 5, 6} 

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	void reverseSubArray(int *arr, int n, int l, int r) {
	    l=l-1;
	    r=r-1;
	   int temp;
	    while(l<r)
	    {
	        temp=arr[l];
	        arr[l]=arr[r];
	        arr[r]=temp;
	        l++;
	        r--;
	    }
	}

};

int main() 
{
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> l >> r;
        Solution ob;
        ob.reverseSubArray(arr, n, l, r);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}