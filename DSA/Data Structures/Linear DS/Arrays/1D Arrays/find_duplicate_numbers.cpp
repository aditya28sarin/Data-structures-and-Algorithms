// URL: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int curr_max=0, max_idx=0;
        
        for(int i=0;i<n;i++){
            int id = nums[i]%n;
            nums[id]+=n;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>curr_max){
                curr_max=nums[i];
                max_idx=i;
            }
        }
        
        return max_idx;
    }
};