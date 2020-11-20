//store inorder traversal of tree in array
//sort array in ascending 
//traverse BT and arary simultaneously and replace BT values by array values



//inorder traversal of BT
void inOrder(vector<int> &vt,Node* root)
{
    
    if(root==NULL)
        return;
        
    if(root->left)
        inOrder(vt,root->left);
        
    vt.push_back(root->data);
    
    if(root->right)
        inOrder(vt,root->right);
 
}
//inorder traversal of BT


// convert to BST
void bst(Node* root, vector<int> &vt, int &i)
{
    if(!root)
    {
        return;
    }
    bst(root->left,vt,i);
    root->data = vt[i++];
      bst(root->right,vt,i);
}

// convert to BST

Node *binaryTreeToBST (Node *root)
{
    vector<int> inOrderVector;
    
    inOrder(inOrderVector,root);
    
    sort(inOrderVector.begin(), inOrderVector.end());

    int i=0;
    bst(root,inOrderVector,i);

    return root;
}
