// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

//soln 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     
        int ptr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }

    }
};


//soln 2

// class Solution {
// public:
    // void moveZeroes(vector<int>& nums) {
     
//         int l=nums[0];
//         int r=nums[1];
        
//         if(nums.size()==1)
//             return;
        
//         while(r!=nums.size())
//         {
//             if(nums[l]==0 && nums[r]!=0)
//             {
//                 swap(nums[l],nums[r]);
//                 l++;
//                 r++;
//             }
            
//             if(nums[l]!=0 && nums[r]==0 || nums[l]!=0 && nums[r]!=0)
//             {
//                 l++;
//                 r++;
//             }
            
//              if(nums[l]==0 && nums[r]==0)
//             {
//                 r++;
//             }
//         }

    // }
// };