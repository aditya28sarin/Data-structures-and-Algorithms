// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to count the number of substrings 
*   starting and ending with 1
*   n: size of string
*   a: input string
*/

//My Naive approach O(n^2)
long binarySubstring(int n, string a){
    
    long count=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='1')
        {
            for(int j=i+1;j<a.length();j++)
            {
                   if(a[j]=='1')
                    count=count+1;
            }
        }
    }
    
    return count;
}



// Efficient Approach O(n)
long binarySubstring(int n, string a){
    
    long count=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='1')
            count++;
    }

    return count*(count-1)/2;
}



// { Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        
        cout << binarySubstring(n, a) << endl;
    }
}
  // } Driver Code Ends