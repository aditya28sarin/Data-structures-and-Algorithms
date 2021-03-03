// URL: https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    stack<int> push_s, pop_s;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_s.push(x);    
    }
    
    void transfer_elements() {
        // transfer the elements from push stack to pop
        while(!push_s.empty()) {
            pop_s.push(push_s.top());
            push_s.pop();
        }    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(pop_s.empty()) 
            transfer_elements();
        
        int popped = pop_s.top();
        pop_s.pop();
        return popped;
    }
    
    /** Get the front element. */
    int peek() {
        if(pop_s.empty()) 
            transfer_elements();
        
        return pop_s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return push_s.empty() && pop_s.empty();    
    }
};