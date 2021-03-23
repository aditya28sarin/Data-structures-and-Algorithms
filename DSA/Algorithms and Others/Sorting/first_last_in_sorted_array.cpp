// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int find_last_pos(vector<int>&nums,int target)
    {
        int last_occur=INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>target)
            {
                high = mid-1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                last_occur = mid;
                low = mid+1;
            }
        }
        return last_occur==INT_MAX ? -1 : last_occur;
    }
    int find_first_pos(vector<int>&nums,int target)
    {
        int first_occur=INT_MAX;
        int low  = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]<target)
            {
                low = mid+1;
            }
            else if(nums[mid]>target)
            {
                high = mid-1;
            }
            else
            {
                first_occur = mid;
                high = mid-1;
            }
        }
        return first_occur==INT_MAX ? -1 : first_occur;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {find_first_pos(nums,target),find_last_pos(nums,target)};
    }
};