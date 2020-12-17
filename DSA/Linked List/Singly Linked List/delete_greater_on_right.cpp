//URL: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

void reverseList(Node** head_ref)
{
    Node* curr_node=(*head_ref);
    Node* prev_node=NULL;
    Node* next_node = NULL;

    while(curr_node!=NULL)
    {
        next_node=curr_node->next;
        curr_node->next=prev_node;
        prev_node=curr_node;
        curr_node=next_node;
    }
    (*head_ref)=prev_node;
}


Node *compute(Node *head)
{
  
    reverseList(&head);
    Node* temp = head;
    int max=head->data;
    while(temp->next!=NULL)
    {
        if(temp->next->data>=max)
        {
            max=temp->next->data;
             temp=temp->next;
        }
        else
        {
            temp->next=temp->next->next;
        }
       
    }
    
    reverseList(&head);
    
    return head;
}
.