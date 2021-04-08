// URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    
    int maxPathSumUtil(TreeNode* root, int *res){
        if(!root){
            return 0;
        }
        
        int left = maxPathSumUtil(root->left,res);
        int right = maxPathSumUtil(root->right,res);
        
        int ms=max(max(left,right)+root->val, root->val);
        int m21=max(ms,left+right+root->val);
        *res=max(m21,*res);
        
        return ms;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumUtil(root,&res);  
        
        return res;
    }
};