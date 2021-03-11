//URL:https://leetcode.com/problems/swap-nodes-in-pairs/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* current = head;
        ListNode* advance = head->next;
        ListNode* previous = nullptr;
        head = nullptr;
        while (current && advance) {
            current->next = advance->next;
            advance->next = current;
            if (previous) previous->next = advance;
            if (head == nullptr) head = advance;
            previous = current;
            current = current->next;
            if (current) advance = current->next;
        }
        return head ? head : current;
    }
};
