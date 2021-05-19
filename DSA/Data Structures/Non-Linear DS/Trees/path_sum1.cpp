// URL: https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool val1,val2;
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        
        if(!root->left && !root->right && root->val==targetSum)
            return true;
        
        
        if(root->left)
            val1 =  hasPathSum(root->left,targetSum-root->val);
        
        
        if(root->right)
            val2 = hasPathSum(root->right,targetSum-root->val);
        
        return val1 || val2;
    }
};