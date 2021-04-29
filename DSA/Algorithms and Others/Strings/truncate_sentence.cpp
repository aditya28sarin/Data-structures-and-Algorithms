// URL: https://leetcode.com/problems/truncate-sentence/

class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string ans="";
        int count=0;
        for(int i=0;i<s.size();i++){
            
            if(isspace(s[i])){
                count++;
            }
             
             if(count==k){
                 break;
             }
               
             ans.push_back(s[i]);
        }
               return ans;
    }
};