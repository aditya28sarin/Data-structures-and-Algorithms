// URL: https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int skip=0;
        int n=nums.size();
        while( i+skip < n){
            nums[i] = nums[i+skip];
            if(nums[i] == val)
                skip++;
            else 
                i++;   
        }
        return n-skip;
    }
};