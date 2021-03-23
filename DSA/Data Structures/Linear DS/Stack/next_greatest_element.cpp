// URL: https://www.geeksforgeeks.org/next-greater-element/


vector<long long> nextLargerElement(vector<long long> arr, int n){
    
    vector<long long > nge(n);
    stack<long long> st;
    
    st.push(arr[n-1]);
    nge[n-1]=-1;
    
    for(int i=n-2; i>=0; i--){
        
        while(!st.empty() && arr[i]>=st.top()){
            st.pop();
        }
        
        if(st.empty()){
            nge[i]=-1;
        }else{
            nge[i]=st.top();
        }
        st.push(arr[i]);
    }
    
    return nge;
}