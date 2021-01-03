// URL: https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

#include<iostream>
using namespace std;

int findCnt(int set[], int n, int sum){

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
    int arr[] = { 3,3,3,3}; 
    int n = sizeof(arr) / sizeof(int); 
    int x = 6; 
  
    cout << findCnt(arr, n, x); 
  
    return 0; 
} 