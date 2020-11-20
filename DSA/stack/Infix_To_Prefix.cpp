#include<bits/stdc++.h>
using namespace std;


int prec(char c)
{

    if(c=='^')
        return 3;
    else if ( c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string exp)
{
    string res;
    std::stack <char> st;
    st.push('N');

    int l =exp.length();

    for(int i =0;i<l;i++)
    {
        //if we find an operand
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z')
            res=res+exp[i];

        //if we find a '('
        else if(exp[i]=='(')
            st.push(exp[i]);


        else if (exp[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                char c = st.top();
                st.pop();
                res=res+c;
            }
            if(st.top()=='(')
            {
                char c= st.top();
                st.pop();
            }
        }

        else
         {
             while(st.top()!='N' && prec(exp[i])<=prec(st.top()))
             {
                char c =st.top();
                st.pop();
                res=res+c;
             }
             st.push(exp[i]);
         }
    }

    while(st.top()!='N')
    {
        char c =st.top();
        st.pop();
        res=res+c;
    }

  return res;  
}

int main()
{
    string exp ="(a-b/c)*(a/k-l)";
    
    reverse(exp.begin(), exp.end());

    for (int i =0;i<exp.length();i++)
    {
        if(exp[i]=='(')
        {
            exp[i]=')';
        }
        else if(exp[i]==')')
        {
            exp[i]='(';
        }
    }
    string res=infixToPostfix(exp);

    reverse(res.begin(), res.end());

    cout<<res;

}
