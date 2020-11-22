vector <int> zigZagTraversal(Node* root)
{
	vector<int> vt;
	
	queue<Node*> q;
	
	stack<Node*> st;
	
    q.push(root);
  
    int level=0;
    
    while(1)
    {
        int cN=q.size();
        
        if(cN==0)
            break;
            
        while(cN--)
        {
         
            if(level%2==0)
            {
                Node* temp=q.front();
                q.pop();
                vt.push_back(temp->data);

                  
                if(temp->left)
                {
                    st.push(temp->left);
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    st.push(temp->right);
                    q.push(temp->right);
                } 
            }  
            
            if(level%2!=0)
            {
                Node* temp=q.front();
                q.pop();
                Node* t1=st.top();
                st.pop();
                vt.push_back(t1->data);
               
               if(temp->left)
                {
                    
                    q.push(temp->left);
                }
                
                  if(temp->right)
                  {
                      
                        q.push(temp->right);
                  }
                
            }
        }
        
        level++;
    }
    return vt;
}