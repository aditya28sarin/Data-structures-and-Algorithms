#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
    
};


//preorder traversal of tree 
void printPreorder(Node* root){
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    
    printPreorder(root->left);
    
    printPreorder(root->right);
    
}

//print inorder
void printInorder(Node* root){
    if(root==NULL)
        return;
    
    printInorder(root->left);
    
    cout<<root->data<<" ";
    
    printInorder(root->right);
    
}

//postorder traversal of tree 
void printPostorder(Node* root){
    if(root==NULL)
        return;
    
    printPostorder(root->left);
    
    printPostorder(root->right);
    
    cout<<root->data<<" ";
}

//iterative preorder traversal 
void iterativePreorder(Node* root){
    
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty()){
        Node* new_node = st.top();
        cout<<new_node->data<<" ";
        st.pop();
        
        if(new_node->right){
            st.push(new_node->right);
        }
        
        if(new_node->left){
            st.push(new_node->left);
        }
        
    }
}

//iterative inorder
void iterativeInorder(Node* root){
    stack<Node*> st;
    Node* curr = root;
    
    while(curr!=NULL || !st.empty()){
        
        
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        
        
        curr=st.top();
        st.pop();
        
        cout<<curr->data<<" ";
        
        curr=curr->right;
    }
}


//iterative preorder with 1 stack 
// So, we can do something like iterative preorder traversal with the following differences:
// a) Instead of printing an item, we push it to a stack.
// b) We push the left subtree before the right subtree.
void iterativePostorderTwostack(Node* root){
    
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    Node* curr =root;
    
    while(!st1.empty()){
        curr=st1.top();
        st1.pop();
        st2.push(curr);
        
        if(curr->left){
            st1.push(curr->left);
        }
        
        if(curr->right){
            st1.push(curr->right);
        }
    }
    
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}


//iterative  postorder with 1 stack 
void iterativePostorderOnestack(Node* root){
    
    stack<Node*> st;
    
    while(true){
        while(root!=NULL){
            st.push(root);
            st.push(root);
            
            root=root->left;
        }
        
        if(st.empty()){
            return;
        }
        
        root=st.top();
        st.pop();
        
        if(!st.empty() && st.top() == root){
            root=root->right;
        }else{
            cout<<root->data<<" ";
            root=NULL;
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "\nRecursive Preorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nIterative Preorder traversal of binary tree is \n"; 
    iterativePreorder(root);
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root); 
    
    cout << "\nIterative Inorder traversal of binary tree is \n"; 
    iterativeInorder(root); 
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root);
    
    cout << "\nIterative Postorder traversal of binary tree with 2 stacks is \n"; 
    iterativePostorderTwostack(root);
    
    cout << "\nIterative Postorder traversal of binary tree with 1 stack is \n"; 
    iterativePostorderOnestack(root);
    
}