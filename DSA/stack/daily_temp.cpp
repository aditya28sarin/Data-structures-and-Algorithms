//URL:https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> ans(T.size(),0);

        for(int i=0;i<T.size();i++){

            while(!st.empty() && T[st.top()]<T[i]){
                ans[st.top()]=abs(i-st.top());
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};
