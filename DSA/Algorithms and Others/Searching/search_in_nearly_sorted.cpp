#include<bits/stdc++.h>
using namespace std;


int BinSearch(int arr[],int low, int high, int element){
    
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==element){
            return mid;
        }

        else if(arr[mid-1]==element){
            return mid-1;
        }

        else if(arr[mid+1]==element){
            return mid+1;
        }

        else if(arr[mid]<element)
            low=mid+2;

        else if(arr[mid]>element)
            high=mid-2;
        
    }

    return -1;
}

int main(){
    int arr[5]={5,10,30,20,40};
    int element = 20;
   
    cout<<BinSearch(arr,0,4,element);
}