bool check(Node *root)
{
    bool flag=true;
    
    queue <Node*> q;
    
    vector<int> vt;
    
    q.push(root);
    int maxIndex=0,index=0,counter=0,maxCounter=0;
    while(1)
    {
        
        counter=q.size();
     
      if (counter == 0) 
            break; 
     
        
        if(counter>maxCounter)
        {
            maxCounter=counter;
            maxIndex=index;
        }
        
        while(counter--)
        {
            Node* temp=q.front();
            q.pop();
            
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            
            if(temp->left==NULL && temp->right==NULL)
            {
                vt.push_back(index);    
            }
        }
        index++;
    }
    
    
    for(int i=1;i<vt.size();i++)
    {
        if(vt[i]!=vt[i-1])
        {
            flag=false;
            break;
        }
    }
    
    return flag;
}