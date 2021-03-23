// URL: https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<len;i++){
            mp[s[i]]+=1;
        }
        int sum=0;
        bool odd_found=false;
        for(auto& c: mp){
            if(c.second %2==0){
                sum+=c.second;
            }else{
                odd_found=true;
                sum+=c.second-1;
            }
        }
        
        if(odd_found){
            sum+=1;
        }
        
        return sum;
    }
};


