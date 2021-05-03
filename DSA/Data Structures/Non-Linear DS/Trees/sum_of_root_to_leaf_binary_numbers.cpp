// URL: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

class Solution {
public:
    
    int curr_sum=0,sum=0;
    
    void preorder(TreeNode* root, int curr_sum){
        if(root==NULL){
            return;
        }
        
        curr_sum=curr_sum*2 + root->val;
        
        if(!root->left && !root->right){
            sum+=curr_sum;
        }
        
        preorder(root->left, curr_sum);
        preorder(root->right,curr_sum);
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        
        preorder(root, 0);
        
        return sum;
    }
};