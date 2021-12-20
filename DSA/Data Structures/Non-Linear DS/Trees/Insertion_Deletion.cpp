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

//insertion of node
Node* insertNode(Node* root, int data){
    
    if(root==NULL){
        return NULL;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }else{
            temp->left = createNode(data);
            return root;
        }

        if(temp->right){
            q.push(temp->right);
        }else{
            temp->right = createNode(data);
            return root;
        }
    }
}


//deletion of node
void deleteDeepest(Node* root, Node* deletedNode){

    queue<Node*> q;
    q.push(root);

    Node* temp;

    while(!q.empty()){
        temp=q.front();
        q.pop();

        if(temp==deletedNode){
            temp=NULL;
            delete(deletedNode);
            return;
        }

        if(temp->left){
            if(temp->left==deletedNode){
                temp->left=NULL;
                delete(deletedNode);
                return;
            }else{
                q.push(temp->left);
            }
        }

         if (temp->right) { 
            if (temp->right == deletedNode) { 
                temp->right = NULL; 
                delete (deletedNode); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
    }
}

Node* deletion(Node* root, int val){
    
    if(root==NULL)
        return NULL;
    
    if(root->left==NULL && root->right==NULL){
        if(root->data == val){
            return NULL;
        }else{
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node* temp_node;
    Node* key_node = NULL;

    while(!q.empty()){
        temp_node = q.front();
        q.pop();

        if(temp_node->data == val){
            key_node=temp_node;
        }

        if(temp_node->left){
            q.push(temp_node->left);
        }

        if(temp_node->right){
            q.push(temp_node->right);
        }
    }

    if(key_node!=NULL){
        int x = temp_node->data;
        deleteDeepest(root,temp_node);
        key_node->data = x;
    }

    return root;
}


int main(){
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = insertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;


    int del_key = 11; 
    root = deletion(root, del_key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
    cout<<endl;

    int val = 7;
    cout<<val<<" is on level: "<<getLevel(root,val)<<endl;
}