#include<bits/stdc++.h>
using namespace std;





int main() 
{ 
    int arr[] = {11, 13, 21, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    std:stack <int> st;
    int i =0;
    while(i<n)
    {
        st.push(arr[i]);
        int j=i;
        while(st.top()<arr[j])
        {
            j++;
        }
        if(j==n)
        {
            arr[i]=
        }
        st.top()=arr[j];
    }
    return 0; 
} 
  