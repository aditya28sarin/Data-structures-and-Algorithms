

//recursive method (method 1)
int getHeight(Node* root)
{
    if(root==NULL)
        return -1;
    
    return 1+max(getHeight(root->left),getHeight(root->right));
}

void updateLevelSum(vector<int> &vt, Node* root, int ht)
{
    if(root==NULL)
        return;
        
    vt[ht]+=root->data;
    
    updateLevelSum(vt,root->left,ht+1);
    
    updateLevelSum(vt,root->right,ht+1);
}

int maxLevelSum(Node* root) {
 
 vector<int> vt(getHeight(root)+1,0);

 updateLevelSum(vt,root,0);
 
 int max=INT_MIN;
 
 for(int i=0;i<vt.size();i++)
 {
     if(vt[i]>max)
        max=vt[i];
 }
 
 return max;
}


//iterative method (method 2)
int maxLevelSum(Node* root) {
    
    int result=root->data;
    
    queue <Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        
        int sum =0;
        
       int count =q.size();
       
       while(count--)
       {
           
           Node* temp = q.front();
           q.pop();
           
           sum=sum+temp->data;
           
           if(temp->left)
            q.push(temp->left);
        
           if(temp->right)
            q.push(temp->right);
       }
       
       result=max(result,sum);
    }
    
    return result;
    
}
