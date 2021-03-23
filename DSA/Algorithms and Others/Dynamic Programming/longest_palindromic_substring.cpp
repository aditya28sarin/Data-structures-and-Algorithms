// URL: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
      
        bool dp[s.size()][s.size()];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<s.size();i++){
            dp[i][i]=true;
        }
        
        string result="";
        result+=s[0];
        
        for(int i=s.size()-1;i>=0;i--){
            
            for(int j=i+1;j<s.size();j++){
                
                if(s[i]==s[j]){
                    if((j-i)==1 || dp[i+1][j-1] ){
                        dp[i][j]=true;
                        
                        if(result.size()< j-i+1){
                            result=s.substr(i,j-i+1);
                        }
                        // result=((j-i+1)>result.size()) ? s.substr(i,j-i+1) : result;
                    }
                }
                
            }
        }
        return result;
    }
};