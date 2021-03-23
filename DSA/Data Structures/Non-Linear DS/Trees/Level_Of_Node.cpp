#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
};


Node* createNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

int getLevel(Node* root, int val){

    queue<Node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int n = q.size();

        while(n>0){
            Node* temp = q.front();
            q.pop();

            if(temp->data == val){
                return level;
            }

            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }

            n--;
        }
        level+=1;
        
    }
}



int main(){
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
 

    int val = 7;
    cout<<val<<" is on level: "<<getLevel(root,val)<<endl;
}