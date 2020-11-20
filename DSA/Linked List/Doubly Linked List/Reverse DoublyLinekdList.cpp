
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node* reverseDLL(Node * head)
{
    Node* currPtr=head;
    Node* prevPtr=NULL;
    Node* nextPtr=NULL;

    while(currPtr!=NULL)
    {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        currPtr->prev=nextPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;

    }
    head=prevPtr;
    return head;
}

