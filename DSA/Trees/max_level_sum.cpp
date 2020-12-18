// URL: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
    
	queue<TreeNode*> q;
	q.push(root);
	int max_sum=INT_MIN;
    int sum=0;
    int level=0;
    int min_level;
	while(1)
        {
            level++;
            int nodes_on_level=q.size();

            if(nodes_on_level==0)
            {
                break;
            }
            
            sum=0;
            while(nodes_on_level--)
            {
                TreeNode* temp = q.front();
                q.pop();
                sum=sum+temp->val;

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            
            if(sum>max_sum)
            {
                max_sum=sum;
                min_level=level;
            }
		
        }	
        return min_level;
    }
};