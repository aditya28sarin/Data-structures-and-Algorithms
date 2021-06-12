class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* currptr = head;
        ListNode* prevptr = NULL;
        ListNode* nextptr = head;
        
        while(nextptr){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        
        head=prevptr;
        
        return head;
    }
};