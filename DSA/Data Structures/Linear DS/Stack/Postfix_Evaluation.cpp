#include<bits/stdc++.h>
using namespace std;


int postfixEvaluation(string exp)
{
    std::stack <int> st;
    st.push(0);
    int l=exp.length();
    for(int i=0;i<l;i++)
    {
        if(isdigit(exp[i]))
        {
            st.push(exp[i]-'0');
           
            
        }
        else
        {
            int val1 =st.top();
            st.pop();
            int val2=st.top();
            st.pop();
             switch (exp[i])  
            {  
            case '+': st.push(val2 + val1); ; break;  
            case '-': st.push(val2 - val1); break;  
            case '*': st.push(val2 * val1); break;  
            case '/': st.push(val2/val1); break;  
            }  
        }
        
    }
    

    int a =st.top();
    return a;
}

int main()
{
  
       int cases;
       cin>>cases;

       while(cases--)
       {
           string exp;
           cin>>exp;
           int val =postfixEvaluation(exp);
           cout<<val<<endl;
       } 

}