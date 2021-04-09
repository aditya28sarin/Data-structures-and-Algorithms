
vector<int> findNextGreater(vector<int> input){
    int size = input.size();
    stack<int> st;
    vector<int> vt;
    for(int i=size-1;i>=0;i--){
        if(size==0){
            vt.push_back(-1);
        }
        else if(size>0 && st.top()>input[i]){
            vt.push_back(st.top());
        }
        else if(size>0 && st.top()<=input[i]){
            while(!st.empty() && st.top()<=input[i]){
                st.pop();
            }

            if(size==0){
                vt.push_back(-1);
            }
            else{
                vt.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    return vt;
}