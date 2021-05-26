// URL: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    
    TreeNode* sortedUtil(vector<int>& nums, int left, int right){
        
        if(left>=right) return NULL;
        
        int mid = left + (right-left)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedUtil(nums,left,mid);
        
        root->right = sortedUtil(nums,mid+1,right);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedUtil(nums,0, nums.size());
    }
};