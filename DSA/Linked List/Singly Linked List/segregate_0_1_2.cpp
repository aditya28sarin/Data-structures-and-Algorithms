// URL: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


Node* segregate(Node *head) {
    
    int count0=0,count1=0,count2=0;
    
    Node* temp1= head;
    
    while(temp1!=NULL)
    {
        if(temp1->data==0)
        count0++;
        
        if(temp1->data==1)
        count1++;
        
        if(temp1->data==2)
        count2++;
        
        temp1=temp1->next;
    }
    
    Node* temp2=head;
    
    while(temp2!=NULL)
    {
        if(count0>0)
        {
            temp2->data=0;
            count0--;
        }
        
        else if(count1>0 && count0==0)
        {
            temp2->data=1;
            count1--;
        }
        
       else if(count2>0 && count1==0 && count0==0)
        {
            temp2->data=2;
            count2--;
        }
        
         temp2=temp2->next;
    }
    return head;
    
}
