URL: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-post/order-traversal/submissions/



class Solution {
public:

        TreeNode* constructFromPrePostUtil(vector<int>& pre, vector<int>& post, int l, int h, int *preIndex, int size) {

            if(*preIndex >= size || l>h){
                return NULL;
            }

            TreeNode* node = new TreeNode(pre[*preIndex]);
            ++preIndex;


            if(l==h){
                return node;
            }

            int i;
            for(i=l;i<=h;i++){
                if(pre[*preIndex]==post[i]){
                    break;
                }
            }


            if(i<=h){
                node->left=constructFromPrePostUtil(pre,post,l,i,preIndex,size);
                node->right=constructFromPrePostUtil(pre,post,i+1,h,preIndex,size);
            }

            return node;
        }




    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex = 0;
        return constructFromPrePostUtil(pre,post,0,pre.size()-1,&preIndex,pre.size());
    }
};
