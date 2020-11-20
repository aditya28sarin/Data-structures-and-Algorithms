// { Driver Code Starts

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
// } Driver Code Ends



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