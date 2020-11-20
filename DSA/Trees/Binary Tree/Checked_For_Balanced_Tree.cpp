
int findHeight(Node* root)
{
    if(root==NULL)
        return -1;
        
        
    return 1+max(findHeight(root->left),findHeight(root->right));
}

// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
   
    if(root==NULL)
        return true;
        
    int LH,RH;
   
  
    LH=findHeight(root->left);
    RH=findHeight(root->right);
    
   
    
     if (abs(LH - RH) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1; 
    
      
    return 0;
     
}
