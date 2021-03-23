// URL:https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/
class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> st;
        string ans="";
        int i=0;
      for(int i=0 ; i<str.length() ; i++){
            if(st.empty())
            {
				st.push(str[i]);
				continue;
			}
            
            if(str[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }

        }
       
        while(!st.empty())
        {
           ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};