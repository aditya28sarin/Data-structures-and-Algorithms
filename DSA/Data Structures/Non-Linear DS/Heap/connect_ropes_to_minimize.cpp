#include<bits/stdc++.h>
using namespace std;

int connectRopes(vector<int>& arr){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
        
    for(int i=0;i<arr.size();i++){
        minHeap.push(arr[i]);
    }
    
    int sum=0;
    while(minHeap.size()>=2){
        int first=minHeap.top();
        minHeap.pop();

        
        int second=minHeap.top();
        minHeap.pop();

        sum=sum+first+second;

        minHeap.push(first+second);

    }


    return sum;
}

int main(){

    vector<int> arr = {1,2,3,4,5};

    cout<<connectRopes(arr);

}