//URL: https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    int maxS;
    stack<int> st;
    stack<int> q;
    CustomStack(int maxSize) {
        maxS=maxSize;
    }
    
    void push(int x) {
       
        if(st.size()>=maxS){
           return;
        } 
        
        st.push(x);
    }
    
    int pop() {
        
        if(st.empty()){
            return -1;
        }
        int val = st.top();
        st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        int diff = st.size() - k;
        
        while(!st.empty()){
            if(diff<=0){
                int no = st.top();
                st.pop();
                no=no+val;
                q.push(no);
            }else{
                q.push(st.top());
                st.pop();
            }
            diff--;
        }
        
        while(!q.empty()){
            int data=q.top();
            st.push(data);
            q.pop();
        }
   }
};
