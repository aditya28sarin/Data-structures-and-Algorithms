
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node()
    {
        data=0;
        next=NULL;
    }
};


//insert Node at the begining
void insertAtBegining(Node** head_ref, int data)
{
    Node* new_node=new Node();

    new_node->data=data;

    new_node->next=(*head_ref);

    (*head_ref)=new_node;
}


//insert node at the end
void insertAtEnd(Node** head_ref, int data)
{
    Node* new_node=new Node();
    Node* prev_node=(*head_ref);
    
    new_node->data=data;

    new_node->next=NULL;
    
    if((*head_ref)==NULL)
        (*head_ref)=new_node;
    else 
    {
        while(prev_node->next!=NULL)
            prev_node=prev_node->next;
        prev_node->next=new_node;
    }
}

//insert after a given node 
void insertAfter(Node** head_ref, int data, int node_no)
{
    
    Node* prev_node=(*head_ref);
    Node* new_node =new Node();
    new_node->data=data;

    while(node_no-->1)
    {
         
        prev_node=prev_node->next;
          
    }

    if(prev_node==NULL)
    {
        cout<<"Previous Node cannot be NULL";
        return;
    }

    new_node->next=prev_node->next;
    prev_node->next=new_node;
}


//delete node from list 
void deleteNode(Node** head_ref, int node_no)
{
    int c=0;
    Node* prev_node =(*head_ref);

    //finding previous node of the node to to be deleted 
    while(node_no-->2)
    {
        prev_node=prev_node->next;
    }

    if((*head_ref)==NULL || prev_node==NULL)
        return;
    
    if(node_no==0)
    {
       (*head_ref)=(*head_ref)->next;
       return;
    }

    //node that is next of the deleted node
    Node *next_node=NULL;

    prev_node->next=prev_node->next->next;
}

//search element in LL
bool search(Node* head,int key)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        if(temp->data==key)
            return true;
        temp=temp->next;
    }
    return false;
}


//get nth node from the beigning 
int GetNth(Node** head_ref, int index){
  int temp=0;
  Node* ptr=(*head_ref);
  while(index-->1)
  {
      ptr=ptr->next;
  }
  return ptr->data;
}


int getNthFromLast(Node** head_ref, int n)
{      int c=0;
       Node* ptr=(*head_ref);
       while(ptr!=NULL)
       {
           ptr=ptr->next;
           c++;
       }
       Node* ptr2=(*head_ref);
       int k=c-n;
       while(k--)
       {
           ptr2=ptr2->next;
       }
       return ptr2->data;
}

//reverse Linked list

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



//swap two nodes in LL
void swapTwoNodes(Node** head_ref, int x, int y)
{
    
    Node* curr1=(*head_ref);
    Node* prev1=NULL;
    
    
    Node* curr2=(*head_ref);
    Node* prev2=NULL;
  
 
        while(curr1 && curr1->data!=x)
    {
        prev1=curr1;
        curr1=curr1->next;
    } 
    
        while(curr2 && curr2->data!=y)
    {
        prev2=curr2;
        curr2=curr2->next;
    }
   
    prev1->next=curr2;
    prev2->next=curr1;
    
    Node* temp = curr1->next;
    curr1->next=curr2->next;
    curr2->next=temp;
}

//find median 
void printMiddle(Node **head_ref)
{
     Node *slow_ptr = (*head_ref);
     Node *fast_ptr = (*head_ref);

    if (fast_ptr!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}


//delete all occurrences of x
void deleteAllOfX(Node** head_ref, int X){
    if((*head_ref)==NULL){
        return;
    }
    
    if((*head_ref)->data==X){
        (*head_ref)=(*head_ref)->next;
    }
    
    Node* temp = (*head_ref);
    while(temp->next!=NULL){
    
        if(temp->next->data==X && temp->next->next!=NULL){
           temp->next=temp->next->next;
        }
        
        else if(temp->next->data == X && temp->next->next==NULL){
            temp->next=NULL;
        }
        else{
            temp=temp->next;
        }
    }
}


//delete list 
void deleteList(Node** head_ref)
{
    Node* temp = (*head_ref);
    while(temp->next!=NULL)
    {
        temp=(*head_ref)->next;
        free((*head_ref));
        (*head_ref)=temp;
    }
}


//no of common elements in linked list 
vector<int> commonNodes(Node** head_ref1, Node** head_ref2){
    Node* temp1=(*head_ref1);
    Node* temp2 = (*head_ref2);
    
    int count =0;
    vector<int> vt;
    unordered_set<int> mp;
    
    while(temp1!=NULL){
        mp.insert(temp1->data);
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        if(mp.find(temp2->data)!=mp.end()){
            count++;
            vt.push_back(temp2->data);
        }
            
        temp2=temp2->next;
    }
    
    return vt;
}


//segregate even and odd positioned nodes
void segregateEvenOdd(Node** head_ref){
    
    if(!(*head_ref)){return;}
    
    Node* end = (*head_ref);
    int count =0;
    while(end->next!=NULL){
        end=end->next;
        count++;
    }
    count = count&1 ? (count/2) + 1 : count/2;
    Node* temp = (*head_ref);
    
    while(count--){
        end->next=temp->next;
        temp->next= temp->next->next;
        end->next->next=NULL;
        temp=temp->next;
        end=end->next;
    }
}


//merge linked lists in place
Node* mergeUtil(Node* head1, Node* head2){
    
    if(head1->next==NULL){
        head1->next=head2;
        return head1;
    }
    
    Node* curr1=head1; 
    Node* next1=head1->next;

    Node* curr2=head2; 
    Node* next2=head2->next;
    
    
    
    while(curr2 && next1){
        
        
        if(curr2->data >= curr2->data && curr2->data <= next1->data){
            next2=curr2->next;
            curr1->next=curr2;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }else{
            if(next1->next){
                  next1=next1->next;
                curr1=curr1->next;
            }else{
                next1->next=curr2;
                return head1;
            }
        }
    }
    
    return head1;
}

Node* merge(Node* head1, Node* head2){
    if(!head1){
        return head2; 
    }   
    
    if(!head2){
        return head1; 
    }  
    
    if(head1->data < head2-> data){
        mergeUtil(head1,head2);
    }else{
        mergeUtil(head2,head1);
    }
}


//check if linked list is Palindrome
bool checkIfPalindrome(Node** head_ref){
    Node* curr = (*head_ref);
    Node* prev=NULL;
    Node* next=NULL;
    queue<int> q;
    bool flag = true;
    
    while(curr!=NULL){
        q.push(curr->data);
        
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    curr=prev;
    
    while(curr!=NULL){
        
        if(q.front()!=curr->data){
            flag=false;
        }
        q.pop();
        curr=curr->next;
    }
    
    return flag;
}

//sort linked list of 0s,1s,2s
Node* sort012(Node* head){
    if(!head || !(head->next)){
        return head;
    }
    
    Node* zeroD = new Node();
    Node* oneD = new Node();
    Node* twoD = new Node();
    
    zeroD->data=0;
    oneD->data=0;
    twoD->data=0;
    
    Node* zero = zeroD, *one = oneD, *two = twoD;
    
    Node* curr = head;
    
    while(curr){
        if(curr->data==0){
            zero->next=curr;
            zero=zero->next;
        }
        else if(curr->data==1){
            one->next=curr;
            one=one->next;
        }
        else if(curr->data==2){
            two->next=curr;
            two=two->next;
        }
        
        curr=curr->next;
    }
    
    
    zero->next =(oneD->next) ? (oneD->next) : (twoD->next);
    one->next=twoD->next;
    two->next=NULL;
    
    head=zeroD->next;
    
    return head;
}



//merge sort 
Node* SortedMerge(Node* a, Node* b); 
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef); 
  
void MergeSort(Node** headRef) 
{ 
    Node* head = *headRef; 
    Node* a; 
    Node* b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    FrontBackSplit(head, &a, &b); 
  
    MergeSort(&a); 
    MergeSort(&b); 
  
    *headRef = SortedMerge(a, b); 
} 

Node* SortedMerge(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) 
{ 
    Node* fast; 
    Node* slow; 
    slow = source; 
    fast = source->next; 
  
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 



//print list
void printList(Node** head_ref)
{
    Node* new_node=(*head_ref);

    while(new_node!=NULL)
    {
        cout<<new_node->data<<"-->";
        new_node=new_node->next;
    }
    cout<<"NULL";
    cout<<endl;
}


int main()
{
    Node* head1=new Node();

    head1=NULL;

    insertAtBegining(&head1,20);
     printList(&head1);
    insertAtBegining(&head1,10);
     printList(&head1);  
    insertAtEnd(&head1,30);
     printList(&head1);  
    insertAtEnd(&head1,40);
     printList(&head1);
     
    insertAfter(&head1,35,3);
     printList(&head1);
        
    deleteNode(&head1,3);
     printList(&head1);
     
     cout<<"The value for the nth node is: "<<GetNth(&head1,2)<<endl;
     cout<<"The value for the nth node from last is: "<<getNthFromLast(&head1,2)<<endl;
     
     reverseList(&head1);
     printList(&head1);
     
     swapTwoNodes(&head1,35,10);
     printList(&head1);
     
     printMiddle(&head1);
     
      insertAtEnd(&head1,40);
     printList(&head1);
     
      insertAtEnd(&head1,60);
     printList(&head1);
     
      insertAtEnd(&head1,70);
     printList(&head1);
     
      insertAtEnd(&head1,40);
     printList(&head1);
     
     
     deleteAllOfX(&head1,40);
     printList(&head1);
     
     deleteList(&head1);
    
    
    Node* head2 =new Node();
    head2=NULL;
    
    insertAtEnd(&head2,10);
     printList(&head2);
     
    insertAtEnd(&head2,15);
     printList(&head2);
     
    insertAtEnd(&head2,15);
     printList(&head2);
     
    insertAtEnd(&head2,10);
     printList(&head2);
    
    vector<int> ans = commonNodes(&head1,&head2);
    cout<<"The common nodes in both Lists are: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    segregateEvenOdd(&head1);
     printList(&head1);
    
    Node* mergedhead = merge(head1, head2); 
  
    printList(&mergedhead);
    
    cout<<checkIfPalindrome(&head2);
    
    Node* head3 =new Node();
    head3=NULL;
    
    insertAtEnd(&head3,2);
     printList(&head3);
     
    insertAtEnd(&head3,1);
     printList(&head3);
     
    insertAtEnd(&head3,1);
     printList(&head3);
     
    insertAtEnd(&head3,0);
     printList(&head3);
     
     
    insertAtEnd(&head3,2);
     printList(&head3);
     
    insertAtEnd(&head3,0);
     printList(&head3);
     
    insertAtEnd(&head3,0);
     printList(&head3);
     
    insertAtEnd(&head3,1);
     printList(&head3);
     
    head3 = sort012(head3);
    printList(&head3);
    
    
    
    
    
    
    
     Node* head4 =new Node();
    head4=NULL;
    
    insertAtEnd(&head4,10);
     printList(&head4);
     
    insertAtEnd(&head4,5);
     printList(&head4);
     
    insertAtEnd(&head4,15);
     printList(&head4);
     
    insertAtEnd(&head4,21);
     printList(&head4);
     
     
    insertAtEnd(&head4,7);
     printList(&head4);
     
    insertAtEnd(&head4,26);
     printList(&head4);
    
    MergeSort(&head4);
    printList(&head4);
} 