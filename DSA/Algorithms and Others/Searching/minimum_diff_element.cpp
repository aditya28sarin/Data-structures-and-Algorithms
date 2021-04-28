#include<bits/stdc++.h> 
using namespace std;


int findMinDiff(int arr[],int low, int high, int element){    
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
            high=mid-1;
        }   
    }


    int left_diff=abs(element-arr[low]);
    int right_diff=abs(element-arr[high]);
  
    if(left_diff<right_diff){
        return arr[low];
    }else{
        return arr[high];
    }
}


int main(){
    int arr[9]={1,2,3,4,8,10,10,12,19};
    int element = 13;
   
    cout<<findMinDiff(arr,0,8,element);
}