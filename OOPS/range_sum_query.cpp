// URL: https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    
    vector<int> ans;
    NumArray(vector<int>& nums) {
        ans.push_back(0);
        for(auto num: nums){
            ans.push_back(ans.back()+num);
        }
    }
    
    int sumRange(int left, int right) {
        
        return ans[right+1]-ans[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */