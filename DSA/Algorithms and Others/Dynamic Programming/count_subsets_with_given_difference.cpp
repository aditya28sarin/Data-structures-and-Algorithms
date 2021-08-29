#include<bits/stdc++.h>
using namespace std;


int countSubsetsWithDiff(vector<int>& v, int sum){
    
    int n=v.size();
    int dp[n+1][sum+1];


    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }

    for(int j=1;j<sum+1;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){

            if(v[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    vector<int> v= {1,1,2,3};
    int diff = 1;

    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    int sum1= (diff+sum)/2;
    cout<<countSubsetsWithDiff(v,sum1);
}