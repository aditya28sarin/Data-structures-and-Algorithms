// URL:https://leetcode.com/problems/is-subsequence/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0,j=0;
        int ans = 0;
        while(j<t.length()){
            
            if(s[i]==t[j]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        if(ans == s.length()){
            return true;
        }else{
            return false;
        }
    }
};