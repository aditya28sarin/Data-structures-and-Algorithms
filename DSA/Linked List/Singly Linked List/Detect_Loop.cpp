
bool detectLoop(Node* head)
{
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    
    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
        if(slow_ptr==fast_ptr)
        {
            return 1;
            
        }
    }
    return 0;
}
