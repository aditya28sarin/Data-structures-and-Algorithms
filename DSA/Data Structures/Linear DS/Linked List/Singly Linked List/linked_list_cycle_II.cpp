/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next || !head->next->next) return NULL;
        
         ListNode* temp1=head;
         ListNode* temp2=head;
        
        while(temp2->next!=NULL && temp2->next->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
            
            if(temp1==temp2) break;
        }
        
        if(temp1!=temp2) return NULL;
        
        temp1=head;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return temp2;
    }
};