#include<bits/stdc++.h>
using namespace std;


void sortHeap(vector<int> input, vector<int>& ans, int k){
    priority_queue<int,vector<int>, greater<int>> minHeap;

    for(int i=0;i<input.size();i++){
        
        minHeap.push(input[i]);
        if(minHeap.size()>k){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while(minHeap.size()>0){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
}

int main(){
    vector<int> input = {6,5,3,2,8,10,9};
    int k=3;

    vector<int> ans;
    sortHeap(input,ans,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}