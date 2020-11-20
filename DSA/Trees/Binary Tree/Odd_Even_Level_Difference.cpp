int getLevelDiff(Node *root)
{
   queue <Node*> q;
   
   int countNodes=0;
   int level=1;
   int sumEven=0;
   int sumOdd=0;
   q.push(root);
   
   while(1)
   {
       countNodes=q.size();
       
       if(countNodes==0)
        break;
        
        while(countNodes--)
        {
            Node* temp = q.front();
            q.pop();
        
            if(level%2==0)
            {
                sumEven=sumEven+temp->data;
            }
            
            if(level%2!=0)
            {
                sumOdd=sumOdd+temp->data;
            }
            if(temp->left)
                q.push(temp->left);
                
            if(temp->right)
                q.push(temp->right);
        }
        level++;
   }
   
   return sumOdd-sumEven;
}

