// URL: https://leetcode.com/problems/univalued-binary-tree/

class Solution {
public:
    
    bool isUnivalTreeUtil(TreeNode* root, int data){
        
        if(root==NULL){
            return true;
        }
        
        if(root->val!=data) return false;
        
        return isUnivalTreeUtil(root->left,data) && isUnivalTreeUtil(root->right,data);
    
    }
    
    
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        int data = root->val;
        
       return isUnivalTreeUtil(root,data);
        
    }
};