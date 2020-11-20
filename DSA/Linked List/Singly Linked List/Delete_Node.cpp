
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    int c=1;


    //while (temp!=NULL)
    //{

        if(x==1)
        {
            head=head->next;
        }
        else
        {
            Node* temp =NULL;
            Node* prevptr=head;
            Node* currptr=head->next;

            while(currptr!=NULL)
            {  c++;
                if(x==c)
                {
                    temp =currptr;
                    currptr=NULL;
                }
                else
                {
                    prevptr=prevptr->next;
                    currptr=currptr->next;
                }

            }
            if(temp!=NULL)
            {
                prevptr->next=temp->next;
            }
        }

    return head;
}
