//recursive 

int getLevelUtil(struct Node* node, int target, int level)
{
    if(node==NULL)
        return 0;
        
    if(node->data==target)
        return level;
    
    int currLevel=getLevelUtil(node->left,target,level+1);
    
    if(currLevel!=0)
    return currLevel;
    
     currLevel=getLevelUtil(node->right,target,level+1);
    
    return currLevel;
}

int getLevel(struct Node *node, int target)
{
    
    
    return getLevelUtil(node,target,1);
    
}


//iterative


int getLevel(struct Node *node, int target)
{
    queue <Node*> st;
    
    st.push(node);
    
    if(node==NULL)
        return 0;
    int c=1;
    Node* back=st.back();
    while(!st.empty())
    {
    
        Node* temp=st.front();
        
        if(temp->left)
            st.push(temp->left);
        
        if(temp->right)
            st.push(temp->right);
       
        

        if(st.front()==back)
        {
            back = st.back();
        if(temp->data==target)
        {
            return c;
        }
        else
            c++;
        }
        
            st.pop();
        
        if(temp->data==target)
        {
            return c;
        }
    }
    
    return 0;
}
