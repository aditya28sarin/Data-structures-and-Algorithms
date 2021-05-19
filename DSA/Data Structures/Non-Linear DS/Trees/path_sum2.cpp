// URL: https://leetcode.com/problems/path-sum-ii/

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
    
    void pathSumUtil(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& currPath){
        
        if(!root) return;
        
        currPath.push_back(root->val);
        
        if(!root->left && !root->right && sum==root->val){
            ans.push_back(currPath);
        }
        
        if(root->left){
            pathSumUtil(root->left,sum-root->val,ans,currPath);
        }
        
        
        if(root->right){
            pathSumUtil(root->right,sum-root->val,ans,currPath);
        }
        
        currPath.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;
        pathSumUtil(root,targetSum,ans,currPath);
        
        return ans;
    }
};