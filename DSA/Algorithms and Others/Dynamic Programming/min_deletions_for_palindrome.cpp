



// URL: https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;



//tabular method 
int LPSTab(string s1,string s2, int n, int m, int dp[][8]){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    string s1="agbcba";
    string s2=s1;
    reverse(s2.begin(),s2.end());

    int n = s1.length();
    int m = s2.length();
    int dp[8][8];
    int LPSLen = LPSTab(s1,s2,n,m,dp);

    cout<<"Minimum no. of deletions: "<<n-LPSLen<<endl;

}