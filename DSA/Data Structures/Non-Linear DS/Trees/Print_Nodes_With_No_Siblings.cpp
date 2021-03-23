





//my soln
void printSibling(Node* root)
{
   queue<struct Node *>q;
   q.push(root);
   vector<int>v;
   while(!q.empty())
   {
       int count=q.size();
       while(count>0)
       {
           struct Node *temp=q.front();
           q.pop();
           if(temp->left!=NULL && temp->right==NULL)
                 v.push_back(temp->left->data);
           if(temp->left) q.push(temp->left);
           if(temp->right!=NULL && temp->left==NULL)
                v.push_back(temp->right->data);
            if(temp->right)q.push(temp->right);
            count--;
       }
   }
   if(v.size()==0)
   cout<<"-1";
   else
   {
       sort(v.begin(),v.end());
       for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
   }
}





//gfg soln 
void Util(Node* root, vector<int> &vt)
{
    if (root==NULL)
        return;
        

    if(root->left!=NULL && root->right!=NULL)
    {
        Util(root->left,vt);
        Util(root->right,vt);
    }
    
    else if(root->right!=NULL)
    {
                vt.push_back(root->right->data);
                Util(root->right,vt);
    }
    else if(root->left!=NULL)
    {
                
                vt.push_back(root->left->data);
                Util(root->left,vt);
    }
}

vector<int> noSibling(Node* root)
{
    vector<int> vt;
    
    Util(root,vt);
    
    if(vt.size()==0)
        vt.push_back(-1);
    
    return vt;

}