    
/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    int c=0;
   Node* ptr=head;
   while(ptr!=NULL)
   {
       c++;
       ptr=ptr->next;
   }
   Node* ptr2=head;
   int k=0,mid,val;

        mid =c/2;
        val=mid+1;

   while(ptr2!=NULL)
   {
       k++;
       if(k==val)
       {
           return ptr2->data;
       }
       ptr2=ptr2->next;
   }
}


///Alternative method using 2 pointers
/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}
