#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3, k = 1; 
    int arr[] = {3,100,1};  
    
     std::stack <int> st;
     st.push(500);
    int i =0,a=1;
    while (i<n)
    {
       if(a==1)
       {
        st.push(arr[i]);
       
       } 
        
        if(st.top()<arr[i+1] && k>0)
        {
            arr[i]=arr[i+1];
            st.pop();
            a=0;
            k=k-1;
        }
        else
        {
            i++;
            a=1;
        }
    }
    
        cout<<"Stack is: ";
        while(!st.empty() )
        {
            if(st.top()!=500)
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            
        }  
    return 0; 
}