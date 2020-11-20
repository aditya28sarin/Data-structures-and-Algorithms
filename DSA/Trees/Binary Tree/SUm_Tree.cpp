
int sum(Node* root)
{
    if(root==NULL)
        return 0;
    
    while(root!=NULL)
    {
        return sum(root->left) + root->data + sum(root->right);
    }
}


// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    
    int ls=sum(root->left);
    int rs=sum(root->right);
    
    
    if((root->data == ls+rs) && isSumTree(root->left) && isSumTree(root->right))
        return true;
}