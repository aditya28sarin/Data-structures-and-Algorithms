// URL: https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
public:
    
    vector<TreeNode*> v;
void inorder(TreeNode* root){     
    if(root){
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
}
TreeNode* increasingBST(TreeNode* root) {
    inorder(root);
    for(int i = 0; i<v.size()- 1; i++){
        v[i]->left = NULL;
        v[i]->right = v[i+ 1];
    }
    v[v.size()- 1]->left = NULL;
    v[v.size()- 1]->right = NULL;
    return v[0];
}
};