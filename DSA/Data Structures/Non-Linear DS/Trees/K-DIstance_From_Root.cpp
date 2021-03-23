vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> vt;
        
    queue <Node*> q;
  
    q.push(root);
    int level=0;
    while(1)
    {
        int cN=q.size();
        
        if(cN==0)
            break;
        
        while(cN--)
        {
            if(level==k)
            {
               vt.push_back(q.front()->data); 
            }
            
            Node* temp=q.front();
            q.pop();
            
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
        level++;
    }
    
    return vt;
  
}