// URL: https://www.geeksforgeeks.org/longest-repeating-subsequence/

#include<bits/stdc++.h>
using namespace std;


int findLongestRepeatingSubSeq(string str){
    
    int n = str.length();
    
    int dp[n+1][n+1];

    for(int i = 0; i <= n; i++){
    
        for(int j = 0; j <= n; j++){
            
            if(i==0 || j==0){
                dp[i][j]=0;
            }

            else if(str[i-1]==str[j-1] && (i!=j)){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    
    return dp[n][n];
}


int main()
{
    string str = "aabb";
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
        << findLongestRepeatingSubSeq(str);
    return 0;
}