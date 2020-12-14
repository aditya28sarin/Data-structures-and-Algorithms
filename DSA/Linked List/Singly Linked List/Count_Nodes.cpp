
// Link list node
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

// head : reference to head of linked list
int getCount(struct Node* head){

    int c=0;

    Node* ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        c++;
    }
return c;
}

