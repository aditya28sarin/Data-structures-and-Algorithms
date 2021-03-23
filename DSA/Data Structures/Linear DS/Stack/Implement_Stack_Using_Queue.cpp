// URL: https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:

    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);        
    }
    
    
    /** Removes the element on top of the stack and returns that element. */
     int pop() {
        while(q1.size()>1)
        {q2.push(q1.front());q1.pop();}
        int a=q1.back(); q1.pop();
        swap(q1,q2);
        return a;
    }
    
    /** Get the top element. */
    int top() {
         while(q1.size()>1)
        {q2.push(q1.front());q1.pop();}
        int a=q1.back();q2.push(q1.back());q1.pop();
        swap(q1,q2);
        return a;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */