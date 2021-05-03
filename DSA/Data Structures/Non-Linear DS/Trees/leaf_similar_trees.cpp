// URL: https://leetcode.com/problems/leaf-similar-trees/

class Solution {
public:
    
    void preorder(TreeNode* root1, vector<int>& v1){
        if(root1==NULL){
            return;
        }
        
        if(!root1->left && !root1->right){
            v1.push_back(root1->val);
        }
        
        preorder(root1->left,v1);
        preorder(root1->right,v1);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
     
        vector<int> v1;
        vector<int> v2;
        
        preorder(root1,v1);
        preorder(root2,v2);
        
        int n = v1.size() > v2.size() ? v1.size() : v2.size();
        
        for(int i=0;i<n;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        
        return true;
    }
};