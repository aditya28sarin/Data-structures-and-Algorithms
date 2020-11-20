#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
public:
    int top;
    Stack(){top=-1;}
    int arr[MAX];
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(top>=MAX-1)
    {
    cout<<x<<" could not be pushed onto to the stack."<<endl;    
        return false;
    }
    else
    {
     top+=1;
    arr[top]=x;
    cout<<x<<" pushed onto to the stack."<<endl;
    return true;
    }
}


bool Stack::isEmpty()
{
    return(top<0);
}

int Stack::pop()
{
    int val;
    if(isEmpty())
    {
    cout<<" Stack is Empty."<<endl; 
    }
    else
    {
        val=arr[top];
     top-=1;
    return val;
    }
}


int Stack::peek()
{
    return arr[top];
}


int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"<<endl; 
    cout<<s.peek()<<" is at the top of the stack.";
    return 0; 
} 