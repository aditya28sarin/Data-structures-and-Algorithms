// URL: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
     
       int j=s.length()-1;
        
        if(s.length()==1 && !isalnum(s[0]))
            return true;
        
        for(int i=0;i<=j;){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            
                i++;
                j--;
        }
        
        return true;
    }
};