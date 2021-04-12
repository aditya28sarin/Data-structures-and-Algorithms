
vector<int> findNextGreater(vector<int> input){
    int size = input.size();
    //first is the element and second is its index
    stack<pair<int,int>> st;
    vector<int> vt;
    for(int i=0;i<n;i++){

        if(size==0){
            vt.push_back(-1);
        }
        else if(size>0 && st.top().first>input[i]){
            vt.push_back(st.top().second);
        }
        else if(size>0 && st.top().first<=input[i]){
            while(!st.empty() && st.top().first<=input[i]){
                st.pop();
            }

            if(size==0){
                vt.push_back(-1);
            }
            else{
                vt.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }


    for(int i=0;i<size;i++){
        vt[i]=i-vt[i];
    }
    return vt;
}