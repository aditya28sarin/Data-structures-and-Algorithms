class Solution {
public:
    
     int findMin(vector<int>& nums,int target) {
       int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        int pv=0;
        while(l<=r){
            
            int m = l + (r-l)/2;
            int prev=(m+n-1)%n;
            int next=(m+1)%n;
            
            if(nums[l]<=nums[r]) return l;
            
            if(nums[m]<=nums[prev] && nums[m]<=nums[next]){
                pv=m;
                break;
            }
            
            if(nums[m]>=nums[l]){
                l=m+1;
            }
            
            else if(nums[m]<=nums[r]){
                r=m-1;
            }
           
        }
        
        return pv;
    }
    
    
    int binSearch(vector<int>& nums, int target, int l, int r){
        
        
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(nums[m]==target){
                return m;
            }
            
            else if(target>=nums[m]){
                l=m+1;
            }
            
            else if(target<=nums[m]){
                r=m-1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int idx=findMin(nums,target);
        
        if(nums[idx]==target) return idx;
        
        int val1=0,val2=0;
        val1=binSearch(nums,target,0,idx-1);
        val2=binSearch(nums,target,idx,nums.size()-1);
        
        
        return val1 > val2? val1 : val2;
        
        return val1;
        
    }
};