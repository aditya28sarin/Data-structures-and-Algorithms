
void traverse(Node* root, unordered_set<int> &us)
{
    if(root==NULL)
        return;
        
    traverse(root->left,us);
    
    us.insert(root->data);
    
    traverse(root->right,us);
    
}



vector <int> printCommon(Node *root1, Node *root2)
{
    vector<int> vt;
    
    unordered_set<int> us1;
    
    unordered_set<int> us2;
    
    traverse(root1,us1);
    
    traverse(root2,us2);
    
    unordered_set<int> :: iterator it;
    
    for(it=us1.begin();it!=us1.end();it++)
    {
        if(us2.find((*it))!=us2.end())
            vt.push_back((*it));
    }
    
    sort(vt.begin(),vt.end());
    
    return vt;
}


