
int toSumTreeUtil(Node *node)
{
    if(node==NULL)
        return 0;
        
    int old=node->data;
    
    node->data=toSumTreeUtil(node->left)+toSumTreeUtil(node->right);
    
    
    return old+node->data;
}


void toSumTree(Node *node)
{
    toSumTreeUtil(node);
}

