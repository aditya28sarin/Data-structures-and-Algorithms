#include<iostream>
#include<vector>
#define MAX_SIZE 2
using namespace std;

 
class stack
{

    public:
    int arr[MAX_SIZE]={0};
    
    int top = -1;
    
    bool push(int x) 
{ 
    if (top >= (MAX_SIZE - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        arr[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
}
    
    int pop () 
    {
        if(top<0)
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else
        {
                 top = top - 1;
        }
   
    
    } 
    
    void print () 
    {
        for (int i = 0; i <=top; i++)
        {
            cout << arr[i] << " ";
        }
    } 
};


 
 
int main () 
{
  
 
stack s;
  
 
s.push (5);
  
 
s.push (15);
  
 
s.push (37);
  
 
s.push (2);
  
 
s.pop ();
  
 
s.push (0);
  
s.pop();
 
s.print ();

 
 
}
