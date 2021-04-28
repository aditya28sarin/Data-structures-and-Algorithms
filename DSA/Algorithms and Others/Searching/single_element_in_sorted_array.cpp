// URL: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        
        if(h==0) return nums[0];
        
        else if(nums[0]!=nums[1]) return nums[0];
        
        else if(nums[h]!=nums[h-1]) return nums[h];
        
        while(l<=h){
            int m = l +(h-l)/2;
            
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1])
                return nums[m];
            
            else if((nums[m]==nums[m-1] && m%2!=0) || (nums[m]==nums[m+1] && m%2==0))
                    l=m+1;
            else
                    h=m-1;
        }
        
        return -1;
    }
};