//URL: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {

  vector<int> vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int last=vec.size()-1;
        int f=0+k-1, l=last-k+1;
        swap(vec[f],vec[l]);
        int i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=vec[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};
