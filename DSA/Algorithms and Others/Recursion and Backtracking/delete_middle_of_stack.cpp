#include<bits/stdc++.h>
using namespace std;


void deleteMiddle(stack<int> &st, int* count){
    if((*count) ==(st.size()/2 +1)){
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    (*count)++;

    deleteMiddle(st,count);
    st.push(temp);
    return;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int count=0;
    stack<int> st2;
    deleteMiddle(st,&count);  

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }  
}