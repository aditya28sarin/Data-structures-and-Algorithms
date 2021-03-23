 
Node* merge(Node* head1, Node* head2)
{
    Node* sort=NULL;
    Node* new_head=NULL;

    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    if(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            sort=head1;
            head1=head1->bottom;
        }
        else
        {
            sort=head2;
            head2=head2->bottom;
        }
    }
    new_head=sort;

    while( head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            sort->bottom=head1;
            sort=head1;
            head1=sort->bottom;
        }
        else
        {
            sort->bottom=head2;
            sort=head2;
            head2=sort->bottom;
        }
    }

        if(head1!=NULL)
        {
            sort->bottom=head1;
        }
        
        if(head2!=NULL)
        {
            sort->bottom=head2;
        }
    return new_head;
}

    
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    // Merge this list with the list on right side
    return merge( root, flatten(root->next) );
}

