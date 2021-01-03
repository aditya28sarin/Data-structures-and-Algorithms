// URL: https://leetcode.com/problems/target-sum/solution/



#include<bits/stdc++.h>
using namespace std;

int findMin(int set[], int n, int target){

    int sum=0;

    for(int i=0;i<n;i++)
        sum+=set[i];

    int s1= (sum+target)/2;

    int dp[n+1][s1+1];

     for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(int i=1;i<=s1;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s1;j++)
        {

            if (set[i-1]>j)
                dp[i][j]=dp[i-1][j];
            
            else
            {
                dp[i][j]=dp[i-1][j] + dp[i-1][j-set[i-1]];
            }
        }
    }

    return dp[n][s1];
}


int main()
{
    int arr[] = {1,1,1,1,1};
    int target=3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMin(arr, n, target);
    return 0;
}