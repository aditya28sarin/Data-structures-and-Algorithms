// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int thirdLargest(int a[],int n);
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<thirdLargest(a,n)<<endl;
    }
}   // } Driver Code Ends




int thirdLargest(int a[], int n)
{
    int first=a[0];
    int second=INT_MIN;
    int third=INT_MIN;

    for(int i=1;i<n;i++)
    {
        if(a[i]>first)
        {
            third=second;
            second=first;
            first=a[i];
        }
        else if(a[i]>second)
        {
            third=second;
            second=a[i];
        }
        else if(a[i]>third)
            third=a[i];
    }

    return third;
}





// int thirdLargest(int a[], int n)
// {
//      set <int> st;
     
     
//      if(n<3)
//         return -1;
     
//      int i=0;
//      while(i<n)
//      {
//          st.insert(a[i]);
//          i++;
//      }
     
//      set <int> :: reverse_iterator it;
//      int count=n;
//      for(it=st.rbegin();it!=st.rend();it++)
//      {
//          if(count==n-2)
//          {
//              return (*it);
//          }
//          count--;
//      }
    
// }
