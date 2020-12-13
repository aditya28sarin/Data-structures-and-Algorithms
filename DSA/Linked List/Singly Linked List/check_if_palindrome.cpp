// URL:https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        bool flag=true;
        queue<int> q;
        
        while(temp!=NULL)
        {
            q.push(temp->val);
            
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;  
        }
       temp=prev;
        while(temp!=NULL)
        {
            if(q.front()!=temp->val)
            {
                flag=false;
            }
            q.pop();
            temp=temp->next;
        }
        return flag;
    }
};