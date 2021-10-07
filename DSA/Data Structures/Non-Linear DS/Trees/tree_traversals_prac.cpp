#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

//recursive preorder
void printPreorder(Node* root){
    
    if(!root) return;

    cout<<root->data<<" ";

    printPreorder(root->left);

    printPreorder(root->right);
}

//recursive inorder
void printInorder(Node* root){
    if(!root) return;

    printInorder(root->left);

    cout<<root->data<<" ";

    printInorder(root->right);

}

//recursive postorder
void printPostorder(Node* root){
    if(!root) return;

    printPostorder(root->left);

    printPostorder(root->right);

    cout<<root->data<<" ";
}


//iterative preorder
void iterativePreorder(Node* root){
    if(!root) return;

    stack<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.top();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->right){
            q.push(temp->right);
        }

        if(temp->left){
            q.push(temp->left);
        }
    }
}

//iterative inorder
void iterativeInorder(Node* root){
    if(!root) return;

    stack<Node*> st;
    Node* curr=root;

    while(curr || !st.empty()){

        while(curr){
            st.push(curr);
            curr=curr->left;
        }

        curr= st.top();
        st.pop();

        cout<<curr->data<<" ";

        curr=curr->right;
    }
}

//iterative postorder - 2 Stack
void iterativePostorderTwostack(Node* root){
    if(!root) return;

    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while(!st1.empty()){

        Node* temp=st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left){
            st1.push(temp->left);
        }

        if(temp->right){
            st2.push(temp->right);
        }
    } 

    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

void levelOrder(Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
      
        while(n--){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        cout<<"| ";
    }
}




int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right =  new Node(3);
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
    
    // cout << "\nIterative Postorder traversal of binary tree with 1 stack is \n"; 
    // iterativePostorderOnestack(root);

    cout<<"\nLevel traversal of binary tree is \n";
    levelOrder(root); 
}