
// URL: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            
            TreeNode* x = q.front();
            q.pop();
            
            if(x->val%2==0 ){
                
                
                if(x->left){
                    if(x->left->left){
                        sum+=x->left->left->val;  
                    }

                    if(x->left->right){
                        sum+=x->left->right->val;  
                    }
                }
                
                
                if(x->right){
                    if(x->right->left){
                        sum+=x->right->left->val;  
                    }
                
                    if(x->right->right){
                        sum+=x->right->right->val;  
                    }

                }
            }
            
            if(x->left){
                q.push(x->left);
            }
            
            if(x->right){
                q.push(x->right);
            }
        }
        
        return sum;
    }
};