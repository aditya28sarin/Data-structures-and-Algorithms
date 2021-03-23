#include<bits/stdc++.h>
using namespace std;

stack <int> st;


int insertAtBack(int x)
{
    if(st.size() == 0 || x<st.top()) 
    st.push(x); 
   
    else
    {
        int a=st.top();
        st.pop();

        insertAtBack(x);

        st.push(a);
    }
}

int sorting()
{

    if(st.size()<=0)
    {
        return 0;
    }

        int x=st.top();
        st.pop();
        sorting();

        insertAtBack(x);

}


int main()
{
    int arr[] = {10, 5, 15, 45}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    for(int i=n-1;i>=0;i--)
    {
        st.push(arr[i]);
    }
  
    sorting(); 

    // while(!st.empty())
    // {
    //     int val=st.top();
    //     st.pop();
    //     cout<<val<<" ";
    // }
    for (int i=0; i<n; i++) 
    {
        arr[i]=st.top();
        st.pop();
        
    }

      for (int i=0; i<n; i++) 
    {
        cout<<arr[i]<<" ";
        
    }
  
    return 0; 

}