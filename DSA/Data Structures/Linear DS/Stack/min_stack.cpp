// URL: https://leetcode.com/problems/min-stack/

#include<stack>
class MinStack {
public:
    stack <int> st1;
    stack <int> st2;
   
    MinStack() {
     
        st1.push(INT_MAX);
        st2.push(INT_MAX);
    }
    
    void push(int x) {
       st1.push(x);
        if(x<=st2.top())
            st2.push(x);
        }
    
    void pop() {
      
        
        if(st2.top()==st1.top())
            st2.pop();
        st1.pop();
        
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};