// URL: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int digit_count=0;
            
            while(nums[i]){
                digit_count++;
                nums[i]=nums[i]/10;
            }
            
            if(digit_count%2==0){
                count++;
            }
        }
        
        return count;
    }
};