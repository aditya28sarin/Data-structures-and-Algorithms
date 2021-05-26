// URL: https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    
    int minDepth(TreeNode* root) {
       if(root == nullptr) return 0;
        
        //now check for leaf node path
        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        if(root->left == nullptr) {
           return 1 +  minDepth(root->right); 
           
        } 
        if(root->right == nullptr) {
            return 1 +  minDepth(root->left);
        }
        
        return 1 + min(minDepth(root->left) , minDepth(root->right));
    }
};