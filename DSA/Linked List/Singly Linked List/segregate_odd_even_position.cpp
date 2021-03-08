//URL: https://leetcode.com/problems/odd-even-linked-list/



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head){return head;}

        ListNode* end = head;
        int count =0;
        while(end->next!=NULL){
            end=end->next;
            count++;
        }
        count = count&1 ? (count/2) + 1 : count/2;
        ListNode* temp = head;

        while(count--){
            end->next=temp->next;
            temp->next= temp->next->next;
            end->next->next=NULL;
            temp=temp->next;
            end=end->next;
        }

        return head;
    }
};
