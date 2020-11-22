
void verticalSumUtil(Node* root, int hd, map<int,int> &mp)
{
    if(root==NULL)
        return;
        
    verticalSumUtil(root->left,hd-1,mp);
    
    mp[hd]+=root->data;
    
    verticalSumUtil(root->right,hd+1,mp);
    
    
}

vector <int> verticalSum(Node *root) {
    
    map <int,int> mp;
    
    map<int,int> :: iterator it;
    
    vector<int> vt;
    
    verticalSumUtil(root,0,mp);
    
    for(it=mp.begin();it!=mp.end();++it)
    {
        vt.push_back(it->second);    
    }
    
    return vt;
}