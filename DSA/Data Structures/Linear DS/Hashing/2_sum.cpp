// URL: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> output;
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
        int key = nums[i];
        if(m.count(target - key) == 0){
            m[key] = i;
        }
        else{
            output.push_back(m[target - key]);
            output.push_back(i);
        }
    }
    return output;        
    }
};