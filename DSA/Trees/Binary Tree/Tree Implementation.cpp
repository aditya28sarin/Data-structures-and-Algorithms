#include<bits/stdc++.h>
#include<cmath>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int data)
{
    Node* new_node= new Node();

    new_node->data=data;
    new_node->left=new_node->right=NULL;

    return new_node;
}

Node* insertNode(Node* root, int key)
{
    if(root==NULL)
        return createNode(key);
    
    if(key<=root->data)
        root->left= insertNode(root->left,key);

    else if (key>root->data)
        root->right= insertNode(root->right,key);

    return root;
}

int searchNode(Node* root, int key)
{
    if(root==NULL)
        return -1;
    
    if(root->data==key)
        return root->data;


    if(key<=root->data)
        return searchNode(root->left, key);
    if(key> root->data)
        return searchNode(root->right,key);
    
}

int iterativeSearch(Node* root, int key)
{
    
    
    while(root->left!=NULL && root->right!=NULL)
    {
        if(key<=root->data)
            root=root->left;
        else if(key>root->data)
            root=root->right;
    }
      return root->data;
}

void inOrder(Node* root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root)
{
    if(root==NULL)
        return;
        
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if(root==NULL)
        return;
        
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}

Node* minELement(Node* root)
{
    while(root->left!=NULL)
    {
        if(root->left->data < root->data)
            root=root->left;
    }
    return root;
}



Node* maxElement(Node* root)
{
    while(root->right!=NULL)
    {
        if(root->right->data > root->data)
            root=root->right;
    }
    return root;
}


int findHeight(Node* root)
{
    int L_Height,R_Height;
    if(root==NULL)
        return -1;
    else
    {
         L_Height=findHeight(root->left);
         R_Height=findHeight(root->right);
        return max(L_Height,R_Height)+1;
    }
}

int main()
{
    Node* root=NULL;
    
    root=insertNode(root,50);
    insertNode(root,25);
    insertNode(root,10);
    insertNode(root,70);
    insertNode(root,75);
    insertNode(root,5);
    insertNode(root,54);

    cout<<"InOrder traversal: ";
    
    inOrder(root);

    cout<<"\n\nPreOrder traversal: ";
    
    preOrder(root);

    cout<<"\n\nPostOrder traversal: ";

    postOrder(root);
     
    cout<<"\n\nSearched Node: "<<searchNode(root,10);

    cout<<"\nIterative Search: "<<iterativeSearch(root,54);

    cout<<"\nMinimum Value is: "<<minELement(root)->data;
    
    cout<<"\nMaximum Value is: "<<maxElement(root)->data;

    cout<<"\nHeight of BST is: "<<findHeight(root);

}