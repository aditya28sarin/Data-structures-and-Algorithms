
// Return the level (0-indexed) with maximum number of nodes.
int maxNodeLevel(Node *root)
{
    queue <Node*> st;
    
    st.push(root);
    
    Node* back=st.back();
    int countNodes=0;
   int max=-1;
    int c=0;
    int maxNode=0;
    while(1)
    {
        int countNodes = st.size();
        
        if (countNodes == 0) 
            break; 
        
         if(countNodes>max)
            {
                max=countNodes;
                maxNode=c;
            }
        
        
        while(countNodes--)
        {
            Node* temp=st.front();
            st.pop();
            if(temp->left)
            {
                st.push(temp->left);
                
            }   
            if(temp->right)
            {
                st.push(temp->right);
               
            }
        
        }
    
        c++;
    }
    
    return maxNode;
}