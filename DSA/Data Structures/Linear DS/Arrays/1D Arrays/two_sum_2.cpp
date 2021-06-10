

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> vt;
        while(l<=r){
            int m = l + (r-l)/2;
            
            if(nums[l] + nums[r] == target){
               vt.push_back(l+1);
                vt.push_back(r+1);
                return vt;
            }
            
            if(nums[l]+nums[r]>target){
                r--;
            }else{
                l++;
            }
        }
        return vt;
    }
};