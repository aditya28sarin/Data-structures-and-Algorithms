#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
};



Node* newNode(int key)
{
    Node* new_node=new Node();

    new_node->data=key;
    
    new_node->left=NULL;

    new_node->right=NULL;

    return new_node;
}

Node* insert(Node* root, int key)
{
    if(root==NULL)
        return newNode(key);


    if(key<root->data)
        root->left=insert(root->left, key);

    else if (key>root->data)
        root->right=insert(root->right,key);

    return root;
}   

void sorted(Node* root, int arr[], int &i)
{
    if(root==NULL)
        return;

    sorted(root->left,arr,i);
    arr[i++]=root->data;
    sorted(root->right,arr,i);
}

Node* treeSort(int arr[], int n)
{
   Node* root=NULL;

   for(int i=0; i<n; i++)
   {
       root=insert(root,arr[i]);    
   }
   
   int i=0;
   sorted(root,arr,i);
}

int main()
{
    int arr[] = {5, 4, 7, 2, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    treeSort(arr, n); 
  
        for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
  
    return 0; 


}