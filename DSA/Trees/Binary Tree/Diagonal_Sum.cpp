
void diagonalSumUtil(Node* root, int vd, map<int,int> &mp)
{
    if(root==NULL)
        return;
        
    mp[vd]+=root->data;
    
    diagonalSumUtil(root->left,vd+1,mp);
    
    diagonalSumUtil(root->right,vd,mp);
    
}

vector <int> diagonalSum(Node* root) {
    
    map<int,int> mp;
    
    vector<int> vt;
    
    diagonalSumUtil(root,0,mp);
    
    
    map<int,int> :: iterator it;
    
    
    for(it=mp.begin();it!=mp.end();++it)
    {
        vt.push_back(it->second);
        
    }
    
    return vt;
}