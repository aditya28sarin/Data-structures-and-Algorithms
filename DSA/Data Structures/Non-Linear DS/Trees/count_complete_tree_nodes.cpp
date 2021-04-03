

// URL: https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        int left_ht=1;
        TreeNode *leftNode = root->left;
        
        while(leftNode){
            leftNode=leftNode->left;
            left_ht+=1;
        }
        
        int right_ht=1;
        TreeNode* rightNode = root->right;
        
        while(rightNode){
            rightNode=rightNode->right;
            right_ht+=1;
        }
        
        if(left_ht==right_ht){
            return pow(2,left_ht)-1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};