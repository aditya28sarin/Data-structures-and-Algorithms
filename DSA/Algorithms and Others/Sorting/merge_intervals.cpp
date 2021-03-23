// URL: https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> arr){
    
    int first = arr[0].first;
    int second = arr[0].second;
    vector<pair<int,int>> ans;
	
	sort(arr.begin(),arr.end());
	
    for(int i=1;i<arr.size();i++){
        
        if(arr[i].first <= arr[i-1].second){
            second = arr[i].second;
            
            if(i==arr.size()-1){
                ans.push_back(make_pair(first,second));
                first= arr[i].first;
                second = arr[i].second;
            }
        }
        else{
            ans.push_back(make_pair(first,second));
            first= arr[i].first;
            second = arr[i].second;
            
             if(i==arr.size()-1){
                ans.push_back(make_pair(arr[i].first,arr[i].second));
            }
            
        }
    }
    
    return ans;
}

int main(){
    vector<pair<int,int>> arr={{1,4},{4,5}};
    
    vector<pair<int,int>> vt;
    vt=mergeIntervals(arr);
    
    vector<pair<int,int>> :: iterator it;
    
    for(it=vt.begin();it!=vt.end();++it){
        cout<<it->first<<","<<it->second<<endl;
    }
}