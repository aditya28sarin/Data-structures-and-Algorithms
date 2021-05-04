// URL: https://leetcode.com/problems/sum-of-left-leaves/

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
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode* x= q.front();
            q.pop();
            
            if(x->left){
                q.push(x->left);
                
                if(!x->left->left && !x->left->right)
                    sum=sum+x->left->val;
            }
            
            if(x->right){
                q.push(x->right);
            }
        }
        return sum;
    }
};