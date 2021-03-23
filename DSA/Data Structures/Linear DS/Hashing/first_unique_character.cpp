// URL: https://leetcode.com/problems/first-unique-character-in-a-string/


class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        
        for(int i=0;i<s.length();i++){
            freq[int(s[i])-97]++;
        }
        
        for(int i=0;i<s.length();i++){
            if(freq[int(s[i])-97]==1){
                return i;
            }
        }
        return -1;
    }
};
