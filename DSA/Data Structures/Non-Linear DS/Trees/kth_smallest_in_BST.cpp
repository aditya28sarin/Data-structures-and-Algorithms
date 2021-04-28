// URL: https://leetcode.com/problems/kth-smallest-element-in-a-bst/



class Solution {
public:
    void solve(TreeNode* root,int k,int &count,int &ans)
    {
        if(!root)return;
        solve(root->left,k,count,ans);
        count++;
        if(count==k)
            ans=root->val;
        solve(root->right,k,count,ans);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int count=0,sol;
        solve(root,k,count,sol);
        return sol;
    }
};