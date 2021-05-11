// URL: https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;


//recursive solution
int LCS(string s1,string s2, int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(s1[n-1]==s2[m-1]){
        return 1+LCS(s1,s2,n-1,m-1);
    }

    else{
        return max(LCS(s1,s2,n,m-1), LCS(s1,s2,n-1,m));
    }
}


//memoized version
int t[1001][1001];
int LCSMem(string s1,string s2, int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(t[m][n]!=-1){
        return t[m][n];
    }

    if(s1[n-1]==s2[m-1]){
        return  t[m][n] = 1+LCS(s1,s2,n-1,m-1);
    }

    else{
        return  t[m][n] =  max(LCS(s1,s2,n,m-1), LCS(s1,s2,n-1,m));
    }

    return t[m][n];
}

//tabular method 
int LCSTab(string s1,string s2, int n, int m, int dp[][8]){
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


string LCSTabPrint(string s1, string s2, int dp[8][8], int n, int m){
    int i=n;
    int j=m;
    string ans;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
        }
    }

    return ans;
}

int main(){
    string s1="abcdegh";
    string s2="abedfhr";

    cout<<LCS(s1,s2,s2.length(),s2.length())<<endl;

    memset(t,-1,sizeof(t));
    cout<<LCSMem(s1,s2,s1.length(),s2.length())<<endl;

    int n = s1.length();
    int m = s2.length();
    int dp[8][8];
    cout<<LCSTab(s1,s2,n,m,dp)<<endl;

    string ans;

    ans = LCSTabPrint(s1,s2,dp,n,m);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.length();i++){
        cout<<ans[i];
    }

}