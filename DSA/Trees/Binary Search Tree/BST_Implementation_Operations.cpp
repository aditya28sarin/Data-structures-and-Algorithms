#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

//creating a new node in a BST
Node* newNode(int item)
{
    Node* new_node=new Node();
    new_node->data=item;
    new_node->left=new_node->right=NULL;
    return new_node;
}

//inorder traversal in BST
void inOrder(Node* root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}


//insert a node with a given key in BST
//void insert(Node** root_ref, int key)
Node* insert(Node* root, int key)
{
    if(root==NULL)
        return newNode(key);
    
    if(key<=root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);

    return root;
}

//searching in a BST
Node* searchBST(Node* root, int key)
{
    if(root==NULL || root->data==key)
        return root;

    if(key<root->data)
        return searchBST(root->left,key);
    else if(key>root->data)
        return searchBST(root->right,key);
}

//iterative search BST
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

//finding minimum element
int minElement(Node* root)
{
    while(root->left!=NULL)
    {
        if(root->left->data < root->data)
            root=root->left;   
    }
    return root->data;
}

//finding maximum element
int maxElement(Node* root)
{
    while(root->right!=NULL)
    {
        if(root->right->data > root->data)
            root=root->right;   
    }
    return root->data;
}

//finding height of BST
int findHeight(Node* root)
{
    if(root==NULL)
        return -1;
    
    return(max(findHeight(root->left), findHeight(root->right))+1);
}

/*------------- Functions for chcekcing if BST---------------*/
bool isBSTUtil(Node* root,int min, int max);
bool checkBST(Node* root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
}
bool isBSTUtil(Node* root,int min, int max)
{
    if(root==NULL)
        return true;

    if(root->data <= min || root->data > max)
        return false;


    return isBSTUtil(root->left,INT_MIN,root->data) && isBSTUtil(root->right,root->data,INT_MAX);
    
   
}
/*------------- Functions for chcekcing if BST---------------*/


/*------------- Delete Node in BST---------------*/
Node* minValue(Node* root);
Node* deleteNode(Node* root, int key)
{
    if(root==NULL)
        return root;
    
    else if(key<root->data) 
        root->left=deleteNode(root->left, key);
    else if(key>root->data)
        root->right=deleteNode(root->right, key);

    //we have found the node we wanted to delete
    else
    {   //if node to be deleted has no child 
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        //if node to be deleted has 1 child
        else if(root->left==NULL)
        {
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root;
            root=root->left;
            delete temp;
        }

        else 
        {
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        
    }

    return root;
    
}

Node* minValue(Node* root)
{
    if(root==NULL)
        return root;
    //we will get min value on left child only hence traversing towards left
    if(root->data > root->left->data)
        root=root->left;
    
    return root;
}
/*------------- Delete Node in BST---------------*/

int main() 
{ 
    Node *root = NULL; 
    root = insert(root, 50); //or
    //insert(&root,50);
    root =  insert(root, 30); 
    root =  insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
   
    // print inoder traversal of the BST 
    inOrder(root); 
   
   std::cout<<"\nMinimum element of the BST is: "<<minElement(root);

  // cout<<"\nMaximum element of the BST is: "<<maxElement(root)<<endl; 

   std::cout<<"\nHeight of BST is: "<<findHeight(root); 

  std:: cout<<"\nIs the Binary Tree a BST? "<<checkBST(root);

   root=deleteNode(root,40);

   std::cout<<"\nBST after deletion: ";
   inOrder(root);
    
    return 0; 
} 

