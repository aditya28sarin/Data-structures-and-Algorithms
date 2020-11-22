//my method 
// A wrapper over leftViewUtil()
vector<int> leftView(Node *root)
{
    vector<int> vt;
    queue <Node*> st;
    st.push(root);    
    int countNodes=0;
    while(1)
    {
        int countNodes = st.size();
        if (countNodes == 0) 
            break; 
        bool flag=true;
        while(countNodes--)
        {
            Node* temp=st.front();
            st.pop();
            if(flag==true)
            {
                vt.push_back(temp->data);
                flag=false;
            }
            if(temp->left)
            {
                st.push(temp->left);
            }   
            if(temp->right)
            {
                st.push(temp->right);
            }
        }
    }
    return vt;
}


//recursive soln 
void leftViewUtil(node* root, int level, int* max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        cout << root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 
  
// A wrapper over leftViewUtil() 
void leftView(node* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
} 



//similar for right view, just write root->right before root->left