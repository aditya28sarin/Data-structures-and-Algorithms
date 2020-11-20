 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	   int l=0;
	   int r=S.length()-1;
	   int flag=1;
	   while(l<=r)
	   {
	       if(S[l]!=S[r])
	       {
	           flag=0;
	       }
	       l++;
	       r--;
	   }
	   
   if(flag==0)
	    return 0;
    else
	    return 1;
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends