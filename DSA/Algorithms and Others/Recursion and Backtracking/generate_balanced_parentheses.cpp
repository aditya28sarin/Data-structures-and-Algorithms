// URL: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    
    void solve(int open, int close, string op, vector<string>& ans){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,ans);
        }
        
        if(close>open){
            string op1=op;
            op1.push_back(')');
            solve(open,close-1,op1,ans);
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string op="";
        solve(open,close,op,ans);
        
        return ans;
    }
};