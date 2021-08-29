
#include<bits/stdc++.h>
using namespace std;

//Bottom Up Approach 
// int knapSack(int w, int wt[], int val[], int n){
//     int dp[n+1][w+1];

//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=w;j++)
//         {
//             if(i==0 || j==0)
//             {
//                 dp[i][j]=0;
//             }

//             else if(wt[i-1]>j)
//             {
//                 dp[i][j]=dp[i-1][j];
//             }

//             else
//             {
//                 dp[i][j]=max(dp[i-1][j], val[i-1]+ dp[i-1][w-wt[i-1]]);
//             }
//         }
//     }

//     return dp[n][w];
// }


//simple recursion
int knapsack(vector<int>& wt, vector<int>& val, int W, int n){
    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1]<=W){
        return max(val[n-1]+ knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
    } else{
        return knapsack(wt,val,W,n-1);
    }
}

//memoized version
int knapsackMem(vector<int>& wt, vector<int>& val, int t[][10], int W, int n){
    if(n==0 || W==0){
        return 0;
    }

    if(t[n][W]!=-1) return t[n][W];

    if(wt[n-1]<=W){
        return t[n][W]= max(val[n-1]+knapsackMem(wt,val,t,W-wt[n-1], n-1), knapsackMem(wt,val,t, W, n-1)); 
    }

    else{
        return t[n][W] = knapsackMem(wt,val,t,W,n-1);
    }
}


//Tabulation Method 
int tb[5][8];
int knapsackTab(vector<int>& wt, vector<int>& val, int W, int n){
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                tb[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                tb[i][j]=max(val[i-1]+tb[i-1][j-wt[i-1]], tb[i-1][j]);
            }else{
                tb[i][j]= tb[i-1][j];
            }
        }
    }

    return tb[n][W];
}

int main()
 {
    vector<int> weights = {1,3,4,5};
        vector<int> val = {1,4,5,7};
        int W = 7;
    int n = weights.size();
    cout<<knapsack(weights,val,W, n)<<endl;


    int t[10][10];
    memset(t,-1,sizeof(t));
    cout<<knapsackMem(weights,val,t,W,n)<<endl;

    // int tb[n+1][W+1];
    cout<<knapsackTab(weights,val,W,n)<<endl;

	return 0;
}