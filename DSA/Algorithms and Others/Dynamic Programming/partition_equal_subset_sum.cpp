#include<iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum){

    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    
    for(int i=1;i<=sum;i++)
        dp[0][i]=false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            
            if (set[i-1]>j)
                dp[i][j]=dp[i-1][j];
            
            else if(set[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-set[i-1]];
            }
        }
    }
    return dp[n][sum];
}

bool partitionSum(int arr[], int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=arr[i];
    
    if(sum%2!=0)
        return false;
    
    else{
        return isSubsetSum(arr, n, sum/2);
    }

}

int main() 
{ 
    int arr[] = { 1,5,11,5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (partitionSum(arr, n) == true) 
        printf("There exists a subset with given sum"); 
    else
        printf("No subset exists with given sum"); 
    return 0; 
} 