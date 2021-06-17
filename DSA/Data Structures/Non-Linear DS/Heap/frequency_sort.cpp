#include<bits/stdc++.h>
using namespace std;

void findKClosest(vector<int>& arr){
    priority_queue<pair<int,int>> maxHeap;
    unordered_map<int,int> mp;
        
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
        

    for(auto it=mp.begin();it!=mp.end();it++){
        maxHeap.push({it->second,it->first});
    }

    while(maxHeap.size()>0){
        int freq=maxHeap.top().first;
        int ele = maxHeap.top().second;

        for(int i=1;i<=freq;i++){
            cout<<ele<<" ";
        }
        maxHeap.pop();
    }
}

int main(){

    vector<int> arr = {1,1,1,3,2,2,4};

    findKClosest(arr);

}