// URL: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int index1=0;
        int index2=0;
        
     while(index1 < m && index2 < n){
         
         int first = nums1[index1];   
         int sec = nums2[index2];
         
        if(first <= sec){
            ans.push_back(first);
            index1++;
        }
        else
        {
            ans.push_back(sec);
            index2++;
        }
        
     } 
        
        
        
        while(index1<m){
            ans.push_back(nums1[index1]);
            index1++;
        }
        
        while(index2<n){
            ans.push_back(nums2[index2]);
            index2++;
        }
        
        for(int i=0;i<m+n;i++){
            nums1[i]=ans[i];
        }
       
    }
};