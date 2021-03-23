// URL: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        bool flag=true;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                flag=false;
                break;
            }
        }
        return flag;
    
    }
};