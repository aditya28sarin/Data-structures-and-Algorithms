
/*
  Return the no. of times search_for value is there in a linked list.
  The input list will have at least one element

  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/

int count(struct node* head, int search_for)
{
    node* ptr=head;
    int c=0;
    while(ptr!=NULL)
    {


        if(ptr->data==search_for)
        {
          c++;
        }
         ptr=ptr->next;
    }


    //cout<<c<<endl;

    return c;
}
