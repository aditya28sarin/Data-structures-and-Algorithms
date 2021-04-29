// URL: https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> st;
        
        for(int i=0;i<allowed.size();i++){
            st.insert(allowed[i]);
        }
        int count=0;
        for(int i=0;i<words.size();i++){
            int sub_count=0;
            for(auto letter : words[i]){
                if(st.find(letter)==st.end()){
                   break;
                }else{
                    sub_count++;
                }     
            }
            if(sub_count==words[i].size())
                count++;
        }
        
        return count;
    }
};