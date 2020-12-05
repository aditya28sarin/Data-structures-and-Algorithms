// URL: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#

// Input:
// push(2)
// push(3)
// pop()
// push(4)
// pop()
// Output: 3 4
// Explanation:
// push(2) the stack will be {2}
// push(3) the stack will be {2 3}
// pop()   poped element will be 3 the 
        // stack will be {2}
// push(4) the stack will be {2 4}
// pop()   poped element will be 4  


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    queue <int> q1,q2;
    int curr_size;

    Stack()
    {
        curr_size=0;
    }

    void push(int data)
    {
        curr_size++;

        q2.push(data);

        while(!q1.empty())
        {
            int val =q1.front();
            q1.pop();
            q2.push(val);
        }

        queue <int> q;

        q=q1;
        q1=q2;
        q2=q;

    }

    void pop()
    {
        if(q1.empty())
            return;
        q1.pop();

        curr_size--;
    }

    int top()
    {
        if(q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return curr_size;
    }

};


int main()
{
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 

  
   cout << "current size: " << s.size() 
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    cout << "current size: " << s.size() 
        << endl; 
    return 0; 
}
