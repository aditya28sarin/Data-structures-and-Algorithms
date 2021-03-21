#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;
};


Node* createNode( int item){
    
    Node* new_node = new Node();
    new_node->data=item;
    new_node->left=NULL;
    new_node->right = NULL;
    return new_node;
}

void inOrder(Node* root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}

//insert node in BST
Node* insert(Node* root, int key){
    
    if(root==NULL){
        return createNode(key);
    }
    Node* temp = root;

    while(1){
        if(key <= temp->data){

            if(temp->left)
                temp=temp->left;
            else{
                temp->left = createNode(key);
                return root;
            }
        }

        if(key > temp->data){
        
            if(temp->right)
                temp=temp->right;
            
            else{
                temp->right = createNode(key);
                return root;
            }
        }
    }   
}

//iterative search 
bool search(Node* root, int key){
    if(root==NULL){
        return false;
    }

    while(root->left || root->right){
        if(key<root->data){
            root=root->left;
        }if(key>root->data){
            root=root->right;
        }if (key==root->data){
            return true;
        }
    }
    return false;
}


//delete node
Node* deleteNode(Node* root, int key){

    if(root==NULL){
        return root;
    }

    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }

    else if(key>root->data){
        root->right = deleteNode(root->right, key);
    }

    else{
        
    }
}


int main(){
    Node* root = NULL;
    root = insert(root, 50);    
    root =  insert(root, 30); 
    root =  insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inOrder(root);

    cout<<endl;
    cout<<search(root,82);

}