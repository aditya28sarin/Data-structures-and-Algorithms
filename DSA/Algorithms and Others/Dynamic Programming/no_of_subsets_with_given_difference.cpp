// URL: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#

#include<bits/stdc++.h>
using namespace std;

bool findMin(int set[], int n){

    int sum=0;

    for(int i=0;i<n;i++)
        sum+=set[i];

    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j]=1;
            
            if(i==0)
                dp[i][j]=0;

            if (set[i-1]>j)
                dp[i][j]=dp[i-1][j];
            
            else if(set[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j] + dp[i-1][j-set[i-1]];
            }
        }
    }


    //find the minimum difference value 
    int diff=INT_MAX;
    for(int i=0;i<=sum/2;i++)
    {
        int first=i;
        int second = sum-i;

        if(dp[n][i]==1 && diff>abs(first-second))
            diff=abs(first-second);
    }

    return diff;
}


int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << findMin(arr, n);
    return 0;
}