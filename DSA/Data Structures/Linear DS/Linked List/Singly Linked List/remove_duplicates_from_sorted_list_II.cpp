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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newNode = new ListNode(0);
        ListNode* temp=newNode;
        bool flag=true;
        while(head){
            
            while(head && head->next && head->val == head->next->val){
                flag=false;
                head=head->next;
            }
            
            if(flag){
                temp->next=head;
                temp=temp->next;
            }
            
            head=head->next;
            flag=true;
        }
        
        temp->next=NULL;
        
        return newNode->next;
    }
};