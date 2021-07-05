
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL){
            return vec;
        }
        int level = 1;
        deque<TreeNode*> q;
        q.push_front(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            while(size--){
                if(level%2!=0){
                    TreeNode* p = q.front();
                    q.pop_front();
                    ans.push_back(p->val);
                    if(p->left){
                        q.push_back(p->left);
                    }
                    if(p->right){
                        q.push_back(p->right);
                    }
                }
                else{
                    TreeNode * p = q.back();
                    q.pop_back();
                    ans.push_back(p->val);
                    if(p->right){
                        q.push_front(p->right);
                    }
                    if(p->left){
                        q.push_front(p->left);
                    }
                }
            }
            vec.push_back(ans);
            level++;
        }
        return vec;
    }
};