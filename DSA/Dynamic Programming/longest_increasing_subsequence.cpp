// URL: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
    
    int n = arr.size();
    vector<int> lis(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            
            if(arr[i]>arr[j] && lis[i]<=lis[j])
                lis[i]=1+lis[j];
        }
    }

    return *max_element(lis.begin(),lis.end());
    }
};