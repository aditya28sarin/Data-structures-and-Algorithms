// URL: https://leetcode.com/problems/reorder-data-in-log-files/

class Solution {
public:
    
    bool static comp(string &a, string &b){
        int p1 = a.find(' ');
        int p2 = b.find(' ');
        string s1 = a.substr(p1+1);
        string s2 = b.substr(p2+1);
        if(s1==s2) return  a < b;
        return s1 < s2;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> letter;
        vector<string> digits;
        vector<string> ans;
        for(int i=0; i<logs.size(); i++){
            int pos = logs[i].find(' ');
            
            if (logs[i][pos+1] >= '0' and logs[i][pos+1] <='9'){
                digits.push_back(logs[i]);
            }else{
                letter.push_back(logs[i]);
            }    
        }
        
        sort(letter.begin(), letter.end(), comp);
        
        ans.insert(ans.end(),letter.begin(),letter.end());
        ans.insert(ans.end(), digits.begin(), digits.end());
        
        return ans;
        
    }
};