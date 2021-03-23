// URL: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int target_2 = target- nums[j] - nums[i];
                
                int f=j+1;
                int b=n-1;
                
                while(f<b){
                    int two_sum = nums[f] + nums[b];
                    
                    if(two_sum < target_2) f++;
                    
                    else if(two_sum > target_2) b--;
                    
                    else{
                        
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[f];
                        quad[3]=nums[b];
                        res.push_back(quad);
                        
                        
                        while(f<b && nums[f] == quad[2]) ++f;
                        while(f<b && nums[b] == quad[3]) --b;
                    }
                }
                
                while(j+1 < n && nums[j+1] == nums[j]) ++j;
            }
            
            
                while(i+1 < n && nums[i+1] == nums[i]) ++i;
        }
        
        return res;
    }
};