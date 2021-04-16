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




//without extra space 

#include<stack>
class MinStack {
public:
    stack <int> st;
    int minVal;

    void push(int x) {
       if(st.empty()){
           st.push(x);
           minVal=x;
       }else{
           if(x>=minVal){
               st.push(x);
           }else if(x<minVal){
               st.push(2*x-minVal);
               minVal=x;
           }
       }
    }
    
    void pop() {
        if(st.empty()){
            return -1;
        }else{
            if(st.top()>=minVal){
                st.pop();
            }else if(st.top()<minVal){
                minVal=2*minVal-st.top();
                st.pop();
            }
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }else{
            if(st.top()>=minVal){
                return st.top();
            }else{
                return minVal;
            }
        }
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return minVal;
    }
};