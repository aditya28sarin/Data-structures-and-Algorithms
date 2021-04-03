// URL: https://leetcode.com/problems/invert-binary-tree/


class Solution {
public:

    
    TreeNode* invertTree(TreeNode* root) {
       
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            swap(temp->left,temp->right);
            
            if(temp->left){
                q.push(temp->left);
            }
            
            
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        return root;
    }
};