// URL: https://www.youtube.com/watch?v=eG5NP5KBJVA&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=23

#include<bits/stdc++.h>
using namespace std;

int patternMatching(string p, string s){
     int len1= p.length();
        int len2=s.length();
        int dp[len1+1][len2+2];
        
        for(int i=0;i<=len1;i++)
        {
            dp[i][0]=0;   
        }
        
        for(int j=0;j<=len2;j++)
        {
            dp[0][j]=0;   
        }
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(p[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    
        return dp[len1][len2];
}

int main()
{
    string p = "aab";
    string s = "abbabb";
    
    patternMatching(p,s)==p.length() ? cout<<true : cout<<false;
  
    return 0;
}