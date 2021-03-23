//URL: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/

#include<bits/stdc++.h>
using namespace std;

int minOperations(int arr[], int x, int l, int r, int count)
{
    if(x<=0)
        return count;
    
    int left = minOperations(arr,x-arr[l],l+1,r,count+1);
    int right = minOperations(arr,x-arr[r],l,r-1,count+1);

    return min(left,right);
}


//with memoization
int minOperationsDP(unordered_map<string,int> &map,int arr[], int x, int l, int r, int count)
{
    if(x<=0)
        return count;
    
    if(l>r)
        return -1;
    
    string key = to_string(l)+"*"+to_string(r)+"*"+to_string(x);
    
    if(map.find(key)!=map.end())
        return map[key];

    int left = minOperationsDP(map,arr,x-arr[l],l+1,r,count+1);
    int right = minOperationsDP(map,arr,x-arr[r],l,r-1,count+1);

    return map[key]=min(left,right);
}

int main()
{
    int arr[]={1,1,4,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=5;
    unordered_map<string,int> map;

    cout<<minOperationsDP(map,arr,x,0,n-1,0);
}