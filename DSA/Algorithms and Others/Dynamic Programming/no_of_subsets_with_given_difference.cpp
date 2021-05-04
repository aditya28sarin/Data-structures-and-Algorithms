// URL: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#

#include<bits/stdc++.h>
using namespace std;

int findMin(int set[], int n, int diff){

    int sum_of_arr=0;

    for(int i=0;i<n;i++)
        sum_of_arr+=set[i];

    int sum=(diff+sum_of_arr)/2;

    int dp[n+1][sum+1];


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
                dp[i][j]=dp[i-1][j] + dp[i-1][j-set[i-1]];
            }
        }
    }

    return dp[n][sum];
}


int main()
{
    int arr[] =  {1,1,2,3};
    int diff=1;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<findMin(arr, n, diff);
    return 0;
}