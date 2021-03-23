// Given an array Arr[], write a program that segregates even and odd numbers. The program should put all even numbers first in sorted order, and then odd numbers in sorted order.

// Example 1:

// Input: 
// N = 7
// Arr[] = {12, 34, 45, 9, 8, 90, 3}
// Output: 8 12 34 90 3 9 45
// Explanation: Even numbers are 12, 34,
// 8 and 90. Rest are odd numbers. After
// sorting even numbers 8 12 34 90 and 
// after sorting odd numbers 3 9 45. Then
// concat both.
// Example 2:

// Input: 
// N = 5
// Arr[] = {0, 1, 2, 3, 4}
// Output: 0 2 4 1 3
// Explanation: 0 2 4 are even and 1 3
// are odd numbers.


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;




//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    multiset<int, greater<int>> st1;
	    multiset<int, greater <int>> st2;
	    
	    for(int i =0;i<n;i++)
	    {
	        if(arr[i]%2==0)
	        {
	            st1.insert(arr[i]);
	        }
	        else
	        {
	            st2.insert(arr[i]);
	        }
	    }
	    
	    int j=0;
	    multiset<int, greater<int>> :: reverse_iterator it1;
	   for (it1 = st1.rbegin(); it1 != st1.rend(); it1++) 
    { 
        arr[j]=(*it1);
        j++;
    } 
	 
	    multiset<int> :: reverse_iterator it2;
	    for (it2 = st2.rbegin(); it2 != st2.rend(); it2++) 
    { 
        arr[j]=(*it2);
        j++;
    } 
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
