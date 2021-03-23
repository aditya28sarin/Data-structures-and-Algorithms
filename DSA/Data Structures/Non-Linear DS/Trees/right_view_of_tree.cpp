// URL: https://leetcode.com/problems/binary-tree-right-side-view/



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
     vector<int> vt;
         
     if(root==NULL)
        return vt;
        
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty())
	{
	    int level=q.size();
	    
	    while(level>0)
	    {
        	TreeNode* temp = q.front();
    		q.pop();
    		level--;
    		if(level==0)
                vt.push_back(temp->val);
        	
        	if(temp->left)
        	{
        		q.push(temp->left);
        	}
        	
        	   	if(temp->right)
        	{
        		q.push(temp->right);
        	}
	
	    }
	}	
	return vt;
    }
};