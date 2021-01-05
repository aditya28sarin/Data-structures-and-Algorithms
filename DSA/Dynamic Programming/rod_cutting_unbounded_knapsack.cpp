#include<iostream>
using namespace std;

int cutRod(int w, int wt[], int val[], int n){
    int dp[n+1][w+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }

            else if(wt[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }

            else
            {
                dp[i][j]=max(dp[i-1][j], val[i-1]+ dp[i-1][w-wt[i-1]]);
            }
        }
    }

    return dp[n][w];
}


int main() 
{ 
    int len[] = {1,2,3,4};
    int price[]={1,5,8,9};
    int L=4; 
    int size = sizeof(len)/sizeof(len[0]); 
    printf("Maximum Obtainable Value is %d", cutRod(L,len,price,size)); 
    getchar(); 
    return 0; 
}