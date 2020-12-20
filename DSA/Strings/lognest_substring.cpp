// URL: https://leetcode.com/problems/longest-common-prefix/submissions/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     
        string ans="";
        int size=strs.size();
        if(size==0)
            return ans;
        
        
        vector<string> temp = strs;
         sort(temp.begin(), temp.end());
        string first=temp[0];
        string last=temp[size-1];
        int first_length=first.length();
        
        int last_length=last.length();
        int i=0,j=0;
        while(i<first_length && j<last_length)
        {
            if(first[i]!=last[j])
            {
                break;
            }
            
            ans+=first[i];
            
            i++;
            j++;
        }
        return ans;
    }
};