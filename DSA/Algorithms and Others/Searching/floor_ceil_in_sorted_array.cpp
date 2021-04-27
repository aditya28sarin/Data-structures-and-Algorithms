#include<bits/stdc++.h> 
using namespace std;

int findFloor(int arr[],int low, int high, int element){    
    int res;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==element){
            return mid;
        }

        else if(arr[mid]<element){
            res=arr[mid];
            low=mid+1;
        }
            
        else if(arr[mid]>element)
        {
            high=mid-1;
        }
            
        
    }

    return res;
}


int findCeil(int arr[],int low, int high, int element){    
    int res;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==element){
            return mid;
        }

        else if(arr[mid]<element){ 
            low=mid+1;
        }
            
        else if(arr[mid]>element)
        {
            res=arr[mid];
            high=mid-1;
        }   
    }
    return res;
}


int main(){
    int arr[9]={1,2,3,4,8,10,10,12,19};
    int element = 5;
   
    cout<<findFloor(arr,0,8,element)<<" is the floor of "<<element<<endl;
    cout<<findCeil(arr,0,8,element)<<" is the ceil of "<<element<<endl;
}