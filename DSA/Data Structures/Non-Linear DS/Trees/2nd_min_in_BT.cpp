// URL: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/


class Solution {
public:
    
    void inorder(TreeNode* root, set<int>& st){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,st);
        
        st.insert(root->val);
        
        inorder(root->right,st);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        
        inorder(root,st);
        int ans;
        if(st.size()<=1){
            ans = -1;
        }else{
            set<int> :: iterator it;
            int c=0;
            for(it=st.begin();it!=st.end();it++){
                c++;
                
                if(c==2){
                    ans = *it;
                }
            }
        }
        
        return ans;
    }
};