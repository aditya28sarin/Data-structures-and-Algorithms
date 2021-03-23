// URL: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string str = s;
        reverse(str.begin(),str.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1]==str[j-1]) 
                    dp[i][j] = 1+dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};