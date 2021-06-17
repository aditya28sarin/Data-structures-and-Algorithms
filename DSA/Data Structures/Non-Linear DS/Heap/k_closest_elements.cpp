#include<bits/stdc++.h>
using namespace std;

void findKClosest(vector<int>& arr, int X, int K){

    priority_queue<pair<int,int>> maxHeap;

    for(int i=0;i<arr.size();i++){
        maxHeap.push({abs(X-arr[i]),arr[i]});

        if(maxHeap.size()>K){
            maxHeap.pop();
        }
    }

    while(maxHeap.size()>0){
        cout<<maxHeap.top().second<<" ";
        maxHeap.pop();
    }
}

int main(){

    vector<int> arr = {5,6,7,8,9};
    int K=3,X=7;

    findKClosest(arr,X,K);

}