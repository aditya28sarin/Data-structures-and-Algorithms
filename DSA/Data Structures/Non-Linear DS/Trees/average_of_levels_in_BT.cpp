// URL: https://leetcode.com/problems/average-of-levels-in-binary-tree/


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            double sum=0;
            for(int i=0;i<n;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left){
                    q.push(x->left);
                }
                
                if(x->right){
                    q.push(x->right);
                }
                sum+=x->val;
            }
            ans.push_back(sum*1.0/n);   
        }
        return ans;
        
    }
};