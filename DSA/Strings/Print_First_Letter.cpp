#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:	
	
	string firstAlphabet(string s)
	{
	    string s1;
	    s1.push_back(s[0]);
	    for(int i =1;i<s.length();i++)
	    {
	        if(isspace(s[i]))
	        {
	            s1.push_back(s[i+1]);
	        }
	    }
	    return s1;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.firstAlphabet(s) << "\n";
   	}

    return 0;
} 
  // } Driver Code Ends