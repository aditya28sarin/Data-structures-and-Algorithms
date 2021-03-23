// URL: https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        
        int max_straight_sum = INT_MIN;
        int min_straight_sum = INT_MAX;
        int temp_max_sum = 0;
        int temp_min_sum = 0;
        int arr_sum = 0;
        
        for(int i=0;i<n;i++){
            
            arr_sum += arr[i];
            
            temp_max_sum += arr[i];
            max_straight_sum = max_straight_sum < temp_max_sum ? temp_max_sum : max_straight_sum;
            temp_max_sum = temp_max_sum < 0 ? 0 : temp_max_sum;
            
            temp_min_sum += arr[i];
            min_straight_sum = min_straight_sum > temp_min_sum ? temp_min_sum : min_straight_sum;
            temp_min_sum = temp_min_sum > 0 ? 0 : temp_min_sum;
        }
        
        if(arr_sum == min_straight_sum){
            return max_straight_sum;
        }
        
        return max(max_straight_sum, (arr_sum - min_straight_sum));
    }
};