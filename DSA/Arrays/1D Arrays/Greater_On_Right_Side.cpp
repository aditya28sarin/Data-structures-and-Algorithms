
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:	
	
	void nextGreatest(int arr[], int n) {
	  
	int max_next=arr[n-1];
	
    arr[n-1]=-1;
        
	  for(int i =n-2;i>=0;i--)
	  {
	      int temp = arr[i];
	      
	      arr[i]=max_next;
	      
	     if(max_next<temp)
	     {
	         max_next=temp;
	     }
	  }
	}


};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.nextGreatest(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
 