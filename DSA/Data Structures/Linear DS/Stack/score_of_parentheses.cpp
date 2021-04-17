// URL: https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> c; int score=0,count=0;
        for(int i=0;i<S.size();++i){
            score=0;
            if(S[i]=='(') c.push(0);
            else{
                while(c.top()!=0){
                    score+=c.top();
                    c.pop();
                }
                score=max(2*score,1); 
                c.pop(); c.push(score);
            }
        }
        while(!c.empty()){
            count+=c.top();
            c.pop();
        }
        return count;
    }
};