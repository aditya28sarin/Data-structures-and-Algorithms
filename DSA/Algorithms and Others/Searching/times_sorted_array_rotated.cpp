#include<bits/stdc++.h>
using namespace std;

int findRotation(int arr[], int n){
    int low=0;
    int high=n-1;

    while(low<=high){

        int mid = low +(high-low)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        if(arr[low]<=arr[high]) return low;

        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
            return mid;
        }

        else if(arr[mid]<=arr[high]){
            high=mid-1;
        }

        
        else if(arr[mid]>=arr[low]){ 
            low=mid+1;
        }
    }

    return -1;
}


//if duplicates

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        
        while(low<high){
            int mid = low + (high-low)/2;
            
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else if(nums[mid]<nums[high]){
                high=mid;
            }else{
                high--;
            }
        }
        
        return nums[high];
    }
};


int main(){
    int arr[8]={11,12,15,18,2,5,6,8};

    cout<<findRotation(arr,8);
}