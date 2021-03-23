//URL: https://leetcode.com/problems/make-the-string-great/
class Solution {
public:
    string makeGood(string s) {
        string s_res;
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty()==true)
            {
                st.push(s[i]);
            }
            else
            {
            if(abs(st.top()-s[i])==32)
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            }
        }
        while(!st.empty())
        {
            s_res.push_back(st.top());
            st.pop();
        }
        reverse(s_res.begin(),s_res.end());
        return s_res;
    }
};
