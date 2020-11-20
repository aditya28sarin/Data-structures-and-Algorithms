#include<iostream>
#include<stack>
using namespace std;

void print(stack <int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main()
{

    stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    print(st);

}