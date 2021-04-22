#include<bits/stdc++.h>
using namespace std;


void insertArr(vector<int> &arr, int temp){
    if(arr.size()==0 || arr[arr.size()-1]<=temp){
        arr.push_back(temp);
        return;
    }

    int val = arr[arr.size()-1];
    arr.pop_back();
    insertArr(arr,temp);
    arr.push_back(val);
}

void sortArr(vector<int> &arr){
    if(arr.size()==1){
        return;
    }   

    int temp = arr[arr.size()-1];
    arr.pop_back();
    sortArr(arr);

    insertArr(arr,temp);
}


int main(){
    vector<int> arr ={2,3,7,6,4,5,9};
    sortArr(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}