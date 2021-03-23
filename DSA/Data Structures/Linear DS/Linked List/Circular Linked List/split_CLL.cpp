// URL:https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#


void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
     Node* temp=head;
     (*head1_ref)=head;
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    
    count++;
    
    if(count%2==0)
        count=count/2-1;
    else
        count=count/2;
    
    Node* temp1=(*head1_ref);
    while(count>0)
    {
        count--;
        temp1=temp1->next;
    }
    (*head2_ref)=temp1->next;
    Node* temp2=temp1->next;
    temp1->next=(*head1_ref);
    
    while(temp2->next!=head)
    {
        temp2=temp2->next;
    }
    temp2->next=(*head2_ref);

}