
/*structure of a node of the linked list is as
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
// Function should return 0 is length is even else return 1
int isLengthEvenOrOdd(struct Node* head)
{
     Node* ptr=head;
     int c=0;
     while(ptr!=NULL)
     {
         ptr=ptr->next;
         c++;
     }
     if(c%2==0)
        return 0;
     else
        return 1;
}
