#include<bits/stdc++.h>
using namespace std;

int paranthesisChecker(string exp)
{
    std::stack <char> st;
    st.push('N');
    
    int flag=0;
    
    if(exp[0]==']' || exp[0]=='}' || exp[0]==')')
        return 0;   
        
    for(int i=0;i<exp.length();i++)
    {
       
       if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        st.push(exp[i]);
        
        else
        {
            
           //if a },),] occurs before a their starting bracket then break
             if(st.top()=='N')
            {
                return 0;
            }
            

            if(exp[i]==')')
                exp[i]='(';
                
            if(exp[i]=='}')
                exp[i]='{';
                
            if(exp[i]==']')
                exp[i]='[';
            
            if(st.top()==exp[i])
            {
                st.pop();
            }

            else
            {
                flag=0;
                break;
            }
                
        }   
    }
   
    return st.top()=='N';
}

int main()
{

    int cases;
    cin>>cases;

    while(cases--)
    {
        string exp;

        cin>>exp;

        int val = paranthesisChecker(exp);

        if(val==1)
            std::cout<<"balanced";
            
        if(val==0)
            std::cout<<"not balanced";
            
        std::cout<<endl;
    }

}