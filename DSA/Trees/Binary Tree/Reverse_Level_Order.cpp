//recursive
void reverseLevelOrder(node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER 
        printGivenLevel(root, i); 
} 
 
/* Print nodes at a given level */
void printGivenLevel(node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        cout << root->data << " "; 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level - 1); 
        printGivenLevel(root->right, level - 1); 
    } 
} 
 
/* Compute the "height" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(node* node) 
{ 
    if (node == NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left); 
        int rheight = height(node->right); 
 
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight + 1); 
        else return(rheight + 1); 
    } 
} 
 

//iterative
vector<int> reverseLevelOrder(Node *root)
{
    stack<Node*> st;
    vector<int> vt;
    queue<Node*> q;
    
    q.push(root);

    while(1)
    {
        int cN=q.size();
        
        if(cN==0)
            break;
            
        while(cN--)
        {
            Node* temp=q.front();
            st.push(temp);
            q.pop();
            
            if(temp->right)
                q.push(temp->right);
            
            if(temp->left)
                q.push(temp->left);
        }
    }
    
    
    while(!st.empty())
    {
        vt.push_back(st.top()->data);
        st.pop();
    }
    return vt;
}