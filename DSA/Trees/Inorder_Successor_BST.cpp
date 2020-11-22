
Node* findMin(Node* root)
{
    Node* temp=root;
    
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    
    return temp;
}


Node * inOrderSuccessor(Node *root, Node *x)
{
   Node* succ;

    if(x->right!=NULL)
    {
       return findMin(x->right);
    }
    
    while(root!=NULL)
    {
  
        if(root->data > x->data)
        {
            succ=root;
            root=root->left;   
        }
        else if(root->data < x->data) 
            root=root->right;
    
       else
        break;
    }
    return succ;
}