#include<bits/stdc++.h> 
using namespace std; 
 
class Node 
{ public:
    int data; 
    Node *left, *right; 
}; 
 
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 


vector<int> printLeftView(Node* root) {
        
        queue<Node*> q;
        q.push(root);
        vector<int> vt;
        
        if(root==NULL)
        return vt;
        
        while(!q.empty()){
            int n = q.size();
            vt.push_back(q.front()->data);
            while(n--){
                Node* temp = q.front();
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return vt;
    }
 

int main() 
{ 
    Node* root = newNode(10); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(8); 
    root->right->right = newNode(15); 
    root->right->left = newNode(12); 
    root->right->right->left = newNode(14); 
 
    vector<int> ans = printLeftView(root);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    } 
} 