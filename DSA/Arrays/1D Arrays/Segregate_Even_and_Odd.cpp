#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


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

// { Driver Code Starts.

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
  // } Driver Code Ends