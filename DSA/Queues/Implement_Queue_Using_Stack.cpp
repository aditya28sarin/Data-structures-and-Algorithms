#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    stack <int> st1,st2;

void enqueue(int data)
{
    st1.push(data);
}


int dequeue()
{
    int val;
    if(st1.empty() && st2.empty())
        cout<<"Error!"<<endl;

    if(st2.empty())
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }   
    }
      val = st2.top();
      st2.pop();
    

      return val;
    
    
}

};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2); 
    q.enqueue(3); 
  
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
  
    return 0; 
}