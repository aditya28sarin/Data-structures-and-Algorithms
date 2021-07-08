class solution{


void insert(stack<int>& st, int temp){

    if(st.empty() || temp>=st.top()){
        st.push(temp);
        return;
    }


    int t=st.top();
    st.pop();

    insert(st,temp);

    st.push(t);

    return;

}


void sort(stack<int>& st){

    if(st.size()==0){
        return;
    }

    int t=st.top();
    st.pop();

    sort(st);

    insert(st,t);

    return;
}

};