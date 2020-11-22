// You are given an array A, of N elements. Find minimum index based distance between two elements
//of the array, x and y.

// Example 1:

// Input:
// N = 4
// A[] = {1,2,3,2}
// x = 1, y = 2
// Output: 1
// Explanation: x = 1 and y = 2. There are
// two distances between x and y, which are
// 1 and 3 out of which the least is 1.
// Example 2:

// Input:
// N = 7
// A[] = {86,39,90,67,84,66,62}
// x = 42, y = 12
// Output: -1
// Explanation: x = 42 and y = 12. We return
// -1 as x and y don't exist in the array.
// Your Task:
// Complete the function minDist() which takes the array, n, x and y as input parameters and returns the minimum distance between x and y in the array. If no such distance is possible then return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 0 <= A[i], x, y <= 105


#include <bits/stdc++.h>
using namespace std;
int minDist(int arr[], int n, int x, int y);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        cout << minDist(a, n, x, y) << endl;
    }
    return 0;
}

int minDist(int arr[], int n, int x, int y) {
   
  int min_d=INT_MAX;
  int p=-1;
  
  for(int i=0;i<n;i++)
  {
      
      if(arr[i]==x || arr[i]==y)
      {
          
        if(p!=-1 && arr[i]!=arr[p])
            min_d=min(min_d,i-p);
        
        p=i;
      }
  }
  
    if(min_d==INT_MAX) 
        return -1; 
        
   return min_d;
}