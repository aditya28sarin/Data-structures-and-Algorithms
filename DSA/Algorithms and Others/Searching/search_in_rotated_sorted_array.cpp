#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n){
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;

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


int BinSearch(int arr[],int low, int high, int element){
    
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==element){
            return mid;
        }

        else if(arr[mid]<=element){
            low=mid+1;
        }

        else if(arr[mid]>element){
            high=mid-1;
        }
    }

    return -1;
}

int main(){
    int arr[8]={11,12,15,18,2,5,6,8};
    int element = 15;
    int n=8;
    int min = findMin(arr,8);

    int x=BinSearch(arr,0,min-1,element);
    int y=BinSearch(arr,min,n-1,element);

    if(x==-1){
        cout<<y;
    }else{
        cout<<x;
    }
}


//new method 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0;
        int r=n-1;
        
        
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }else{
                r=m;
            }
        }
        
        if(target<=nums[n-1]){
            return bin_search(nums,target,l,n-1);
        }else{
            return bin_search(nums,target,0,l-1);
        }
    }
    
  
    int bin_search(vector<int>& nums, int target, int l, int r){
        
        while(l<=r){
            int mid = l +(r-l)/2;
            
            if(nums[mid]==target) return mid;
            
            else if(nums[mid]>target) r=mid-1;
            
            else l=mid+1;
        }
        
        return -1;
    }
};


//new method with duplicates
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(target==nums[m]) return true;
            
            else if(nums[m]==nums[l] && nums[m]==nums[r]){
                l++;
                r--;
            }
            
            else if(nums[m]>=nums[l]){
                if((target>=nums[l]) && (target<nums[m])){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }else{
                if((target>nums[m]) && (target<=nums[r])){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
        }
        
        return false;
    }
};