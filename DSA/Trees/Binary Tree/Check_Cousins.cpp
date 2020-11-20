bool isCousins(Node *root, int a, int b)
{
    
    if(root==NULL)
        return false;
 
    queue <Node*> st;
 
    st.push(root);    
 
    int countNodes=0;
    
    while(!st.empty())
    {
        int countNodes = st.size();
        
        // if (countNodes == 0) 
        //     break;
        
        bool aPresent=false;
        bool bPresent=false;
        
        while(countNodes--)
        {
            Node* temp=st.front();
            st.pop();
           
           if(temp->left && temp->right)
           {
               if(temp->left->data==a && temp->right->data==b)
                return false;
                
               if(temp->left->data==b && temp->right->data==a)
                return false;
           }
           
           if(temp->data==a)
            aPresent=true;
            
        
           if(temp->data==b)
            bPresent=true;    
           
            if(temp->left)
            {
                st.push(temp->left);
            }   
            
            if(temp->right)
            {
                st.push(temp->right);
            }
        }
      if(aPresent & bPresent)
        return true;
    }
    return false;
}




//recursive 
int isSibling(struct Node *root, struct Node *a, struct Node *b) 
{ 
    // Base case 
    if (root==NULL)  return 0; 
  
    return ((root->left==a && root->right==b)|| 
            (root->left==b && root->right==a)|| 
            isSibling(root->left, a, b)|| 
            isSibling(root->right, a, b)); 
} 
  
// Recursive function to find level of Node 'ptr' in a binary tree 
int level(struct Node *root, struct Node *ptr, int lev) 
{ 
    // base cases 
    if (root == NULL) return 0; 
    if (root == ptr)  return lev; 
  
    // Return level if Node is present in left subtree 
    int l = level(root->left, ptr, lev+1); 
    if (l != 0)  return l; 
  
    // Else search in right subtree 
    return level(root->right, ptr, lev+1); 
} 
  
  
// Returns 1 if a and b are cousins, otherwise 0 
int isCousin(struct Node *root, struct Node *a, struct Node *b) 
{ 
    //1. The two Nodes should be on the same level in the binary tree. 
    //2. The two Nodes should not be siblings (means that they should 
    // not have the same parent Node). 
    if ((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b))) 
        return 1; 
    else return 0; 
} 