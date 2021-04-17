// URL: https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int depth=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='('){
                depth++;
            }
            if(depth>1){
                ans+=S[i];
            }
            if(S[i]==')'){
                depth--;
            }
        }
        
        return ans;
    }
};