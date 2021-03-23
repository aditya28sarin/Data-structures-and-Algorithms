#include<bits/stdc++.h>
using namespace std;

 int check(std::stack <int> st, int n, int arr[])
{

    int arr1[n];
    for(int i=0,j=n-1;i<n,j>=0;i++,j--)
    {   
        
        st.push(arr[i]);
     
        int val = st.top();
        st.pop();
        arr1[j]=val;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }

    int i=0,a=1;
    while(a==1 && i<n-1)
    {
        if(arr1[i]>arr1[i+1])
            a=0;
        i++;
    }

    return a;
}

int main()
{
    std::stack <int> st; 
    int arr[]={88,55,13,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a=check(st,n,arr);
    cout<<endl;

    if(a==1)
    
        cout<<"Array is stack sortable!"<<endl;
    else
        cout<<"Array is not stack sortable!"<<endl;

    return 0;
}