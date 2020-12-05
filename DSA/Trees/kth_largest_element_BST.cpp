// URL: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#



void Util(Node* root, int K,vector<int> &vt)
{
 
    if(root==NULL)
        return;
    
        
     Util(root->left,K,vt);
     
     vt.push_back(root->data);
     
     Util(root->right,K,vt);
    
}

int kthLargest(Node *root, int K)
{
    vector<int> vt;
     Util(root,K,vt);
     
     sort(vt.begin(),vt.end());
     
     for(int i=vt.size()-1;i>=0;i--)
    {
        K--;
        if(K==0)
        {
            return vt[i];
        }
    }
}
