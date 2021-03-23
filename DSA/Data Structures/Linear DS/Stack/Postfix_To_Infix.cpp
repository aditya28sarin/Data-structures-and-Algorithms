#include<bits/stdc++.h>
using namespace std;


string prefixToinfix(string exp)
{

    string res;
    std::stack <string> st;
    int l = exp.length();
    st.push("N");
    for(int i =0;i<l;i++)
    {
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z' )
            st.push(string(1,exp[i]));

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')
        {
            string val1=st.top();
            st.pop();
            string val2=st.top();
            st.pop();

            res='(' + val1 + exp[i] + val2 +')';
            st.push(res);
        }
    }
    return st.top();

}

int main()
{
    string exp ="ab*c+";
    
   
    string s = prefixToinfix(exp);

    reverse(s.begin(), s.end());

      for (int i =0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
        }
        else if(s[i]==')')
        {
            s[i]='(';
        }
    }

    cout<<s;

    }