//recursive

bool checkUtil(Node* root1, Node* root2)
{
    if(!root1 && !root2)
        return true;
    
    
    if(root1 && root2 && (root1->data == root2->data))
    {
        return checkUtil(root1->left,root2->right) && checkUtil(root1->right, root2->left);
    }
    
    return false;
}

bool isSymmetric(struct Node* root)
{

return checkUtil(root,root);
    
}

//iterative 
//check afterwards