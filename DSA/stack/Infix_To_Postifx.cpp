#include<bits/stdc++.h>
using namespace std;

// //operator precedence function
// int prec(char c)
// {
//     if( c=='^')
//         return 3;
//     else if( c=='*' || c=='/')
//         return 2;
//     else if( c=='+' || c=='-')
//         return 1;
//     else 
//         return -1;
// }

// void infixToPostfix(string infix_string)
// {
//     stack <char> st;
//     st.push('N');
//     int l = infix_string.length();
//     string postfix_string;

//     for(int i=0; i<l;i++)
//     {
//         // If the scanned character is an operand, add it to output string. 
//         if(infix_string[i]>='a' && infix_string[i]<='z' || infix_string[i]>='A' && infix_string[i]<='Z')
//             postfix_string=postfix_string + infix_string[i];    

//         // If the scanned character is an ‘(‘, push it to the stack.
//         else if ( infix_string[i]=='(')
//             st.push(infix_string[i]);

//          // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered. 
//         else if (infix_string[i]==')')
//         {
//             while(st.top()!='N' && st.top()!='(')
//             {
//                 char c= st.top();
//                 st.pop();
//                 postfix_string=postfix_string+c;
//             }
//             if(st.top()=='(')
//             {
//                 char c=st.top();
//                 st.pop();
//             }
//         }

//          //If an operator is scanned 
//          else
//          {
//              while (st.top()!='N'  &&  prec(infix_string[i]) <= prec(st.top()))
//              {
//                  char c =st.top();
//                  st.pop();
//                  postfix_string=postfix_string+c;
//              }
//              st.push(infix_string[i]);   
//          }
//     }
    
//     //If an operator is scanned 
//     while(st.top()!='N')
//     {
//         char c=st.top();
//         st.pop();
//         postfix_string=postfix_string+c;
//     }
//     cout<<postfix_string<<endl;
// }


int prec(char op)
{
    if(op=='^')
        return 3;
    if(op=='*' || op=='/')
        return 2;
    if(op=='+' || op=='-')
        return 1;
    else
        return -1;
}


void infixToPostfix(string exp)
{
    std::stack <char> st;
    st.push('N');
    string ns;
    int len = exp.length();
    int i=0;
    while(i<len)
    {
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z')
        {
            ns+=exp[i];
        }
        
        else if(exp[i]=='(')
            st.push(exp[i]);

        else if(exp[i]==')')
        {
            while(st.top()!='(')
            {
                char c=st.top();
                st.pop();
                ns+=c;
            }
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        }
        else
        {
            while(prec(exp[i])<=prec(st.top()))
            {
            char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(exp[i]); 
        } 
        i++;
    }

 while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    } 
      
    cout << ns << endl; 
    i++;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;

}

