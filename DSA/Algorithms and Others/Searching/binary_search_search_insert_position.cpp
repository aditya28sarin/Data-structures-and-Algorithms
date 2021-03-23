// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it 
//would be if it were inserted in order.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
// Example 4:

// Input: nums = [1,3,5,6], target = 0
// Output: 0
// Example 5:

// Input: nums = [1], target = 0
// Output: 0
 

 
-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------



class Solution {
public:
    
    int binarySearch(int l, int r, vector<int> &nums, int target)
    {
        if(r>=l)
        {
            int mid = l +(r-l)/2;
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[mid]>target)
                return binarySearch(l,mid-1,nums,target);
            
            return binarySearch(mid+1,r,nums,target);
        }
        return -1;
    }
    
    
    int searchInsert(vector<int>& nums, int target) {
        
        int l=0;
        int r=nums.size()-1;
        
        int index= binarySearch(l,r,nums,target);
        if(index==-1)
        {
            if(target<nums[0])
                    index= 0;
            else if(target>nums[nums.size()-1])
                    index= nums.size();
            
            else
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(target<nums[i])
                    {
                        index=i;
                        break;
                    }
                }
               
            }
        }
        return index;
    }
};