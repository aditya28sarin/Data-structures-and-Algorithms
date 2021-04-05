// URL: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    
    int dia(TreeNode* root, int* res){
        if(root==NULL){
            return 0;
        }
        
        int l = dia(root->left, res);
        int r =dia(root->right, res);
        
        int temp = max(l,r)+1;
        
        int ans = max(temp, l+r+1);
        
        *res= max(*res,ans);
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        return dia(root,&res);
    }
};