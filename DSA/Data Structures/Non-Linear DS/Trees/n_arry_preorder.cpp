// URL: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int> ans;
        if(root==NULL)
            return ans;
        stack<Node *> stk;
        stk.push(root);
        
        while(!stk.empty()){
            Node *curr=stk.top();
            stk.pop();
            ans.push_back(curr->val);
            for(int i=curr->children.size()-1;i>=0;i--){
                stk.push(curr->children[i]);
            }
        }
        return ans;
    }
};