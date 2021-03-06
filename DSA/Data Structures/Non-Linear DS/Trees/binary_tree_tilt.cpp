// URL: https://leetcode.com/problems/binary-tree-tilt/

class Solution {
public:
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        
        int res = 0;
        
        postorder(root, res);
        
        return res;
    }
private:
    int postorder(TreeNode* root, int& res){
        if(root == NULL) return 0;
        
        int leftsum= postorder(root->left,res);
        
        int rightsum = postorder(root->right,res);
        
        res += abs(leftsum - rightsum);
        
        return leftsum + rightsum + root->val;
        
    }
};