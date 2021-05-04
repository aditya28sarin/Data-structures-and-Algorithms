// URL: https://www.youtube.com/watch?v=QihB4bI6BJw&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=12

#include<bits/stdc++.h>
using namespace std;

int findMin(int set[], int n){

    int sum=0;

    for(int i=0;i<n;i++)
        sum+=set[i];


    bool dp[n+1][sum+1];

     for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {

            if (set[i-1]>j)
                dp[i][j]=dp[i-1][j];
            
            else
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-set[i-1]];
            }
        }
    }

    vector<int> vt;

    for(int j=0;j<=sum/2;j++){
        if(dp[n][j]==true){
            vt.push_back(j);
        }
    }


    int mn = INT_MAX;
    for(int i=0;i<vt.size();i++){
        mn=min(mn,sum-2*vt[i]);
    }

    return mn;
}


int main()
{
    int arr[] = {1,6,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMin(arr, n);
    return 0;
}