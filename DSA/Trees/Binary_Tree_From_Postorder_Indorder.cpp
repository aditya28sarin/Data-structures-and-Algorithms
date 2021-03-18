// URL: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/

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
    
    
    int search(vector<int> &inorder, int l, int h, int value){
        int i;
        for(i=l;i<=h;i++){
            if(value==inorder[i]){
                break;
            }
        }
        
        return i;
    }
    
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int l, int h, int *pIndex){
        
        if(l > h){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(postorder[*pIndex]);
        (*pIndex)--;
        
        if(l==h){
            return node;
        }
        
        int inIndex = search(inorder , l, h, node->val);
        
        
        node->right = buildTreeUtil(inorder, postorder, inIndex+1, h, pIndex);
        node->left = buildTreeUtil(inorder, postorder, l, inIndex-1, pIndex);
        
        return node;
    }
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pIndex = postorder.size()-1;
        return buildTreeUtil(inorder,postorder, 0, postorder.size()-1,&pIndex);
    }
};