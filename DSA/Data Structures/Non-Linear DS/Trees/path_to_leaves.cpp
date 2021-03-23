// URL: https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    
    void binaryTreePathsUtil(TreeNode* root, string path, vector<string> &paths)
    {
        path+=std::to_string(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            paths.push_back(path);
            return;
        }
        
        if(root->left)
        {
            binaryTreePathsUtil(root->left,path+"->",paths);
        }
        
        if(root->right)
        {
            binaryTreePathsUtil(root->right,path+"->",paths);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> vt;
        
        if(root==NULL)
            return vt;
        
        binaryTreePathsUtil(root,"",vt);
        
        return vt;
    }
};