//my soln 

void trav(Node* root, int target, vector <int> &vt, Node* temp)
{
     static bool flag =false;
     
     if(root==NULL || root->data==target)
     {
         if(root->data==target)
            flag=true;
        return;
     }
     
    if(root->left)
    {
        trav(root->left,target,vt,temp);
    }
    
    if(flag==true)
            vt.push_back(root->data);
            
    if(root==temp && flag==true)
        return;

    if(flag==false)
    {
        if(root->right)
        {
            trav(root->right,target,vt,temp);
        }
        
        if(flag==true)
                vt.push_back(root->data);
                
        if(root==temp && flag==true)
            return;
    }
}


vector<int> Ancestors(struct Node *root, int target)
{
    Node* temp =root;
    
    vector<int> vt;
    
    trav(root,target,vt,temp);
    
    return vt;
}



//gfg

vector<int> Ancestors(struct Node *root, int target)
{
    if (root == NULL) 
     return false; 
  
  if (root->data == target) 
     return true; 
  
  /* If target is present in either left or right subtree of this node, 
     then print this node */
  if ( printAncestors(root->left, target) || 
       printAncestors(root->right, target) ) 
  { 
    vt.push_back(root->data);
    return true; 
  } 
  
  /* Else return false */
  return false; 
}
