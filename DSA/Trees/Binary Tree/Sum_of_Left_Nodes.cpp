int leftLeavesSum(Node *root)
{
    Node* temp=root;
    
    static int sum=0;
    
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->left!=NULL)
    {
        if(temp->left->left==NULL)
        {
            sum=sum+temp->left->data;
        }
    } 
        leftLeavesSum(temp->left);
     
        leftLeavesSum(temp->right);
        
    return sum;
}