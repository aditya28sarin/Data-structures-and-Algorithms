// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack <ll> st;
    queue <ll> q1;
    while(k!=0)
    {
        int val = q.front();
        q.pop();
        st.push(val);
        k--;
    }
    
     while(!st.empty())
    {
        
        int val = st.top();
        st.pop();
        q1.push(val);
    }
    
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        q1.push(val);
    }
    
   
    return q1;
}