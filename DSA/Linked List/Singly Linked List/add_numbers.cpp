// URL: https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    
void insertAtEnd(ListNode** head_ref, int data)
{
    ListNode* new_node=new ListNode();
    ListNode* prev_node=(*head_ref);
    
    new_node->val=data;

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
    
    
ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        
    //if list 1 is empty simply return list 2
    if(!head1){
        return head2;
    }
    
    //if list 2 is empty simply return list 1
    if(!head2){
        return head1;
    }
    
    //check which list is longer in length and make that head1
    ListNode* head_ref1=head1;
    ListNode* head_ref2=head2;
    int size1=0,size2=0;
    while(head_ref1!=NULL){
        size1++;
        head_ref1=head_ref1->next;
    }

     while(head_ref2!=NULL){
        size2++;
        head_ref2=head_ref2->next;
    }

    if(size2>size1){
        ListNode* temp;
        temp=head1;
        head1=head2;
        head2=temp;
    }
       
    
    ListNode* temp1=head1;
    ListNode* temp2 =head2;
    int cry=0; //carry
    
    while(temp1){
        
        if(temp1 && temp2){
            if((temp1->val+temp2->val+cry)/10==0){
                temp1->val = temp1->val + temp2->val + cry;
                cry=0;
            }
            else if((temp1->val + temp2->val +cry)/10!=0){
               int data = (temp1->val + temp2->val + cry)%10;
                cry=(temp1->val + temp2->val + cry)/10;
                
                temp1->val=data;
            }
            
            temp1=temp1->next;
            temp2=temp2->next;
        }else{
            if((temp1->val+cry)/10==0){
                temp1->val = temp1->val + cry;
                cry=0;
            }
            else if((temp1->val +cry)/10!=0){
                int data  = (temp1->val + cry)%10;
                cry= (temp1->val + cry)/10;
                
                temp1->val=data;
            }
            temp1=temp1->next;
        }
        
    }
   
    //if carry is not 0 then insert a node at end with value 1
    if(cry!=0){
        insertAtEnd(&head1,cry);
    }
    
    return head1;   
    }      
};