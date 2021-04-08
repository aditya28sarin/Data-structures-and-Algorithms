// URL: https://leetcode.com/problems/cousins-in-binary-tree/
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
    
    int findHeight(TreeNode* root, int value, int &parent, int height){
        if(!root){
            return 0;
        }
        
        if(root->val == value){
            return height;
        }
        
        parent = root->val;
        
        int left = findHeight(root->left, value, parent, height+1);
        
        if(left){
            return left;
        }
        
        parent = root->val;
        
        int right = findHeight(root->right, value, parent, height+1);
        
        return right;
        
    }

    bool isCousins(TreeNode* root, int x, int y) {
        
        if((root == NULL) || (root->val == x) || (root->val == y)){
            return false;
        }
        TreeNode* curr = root;
        
        int xParent = -1;
        
        int xHeight = findHeight(curr, x, xParent, 0);
        
        int yParent = -1;
        
        int yHeight = findHeight(curr, y, yParent, 0);
        
        if((xHeight == yHeight) && (xParent != yParent)){
            return true;
        }
        return false;
    }
};