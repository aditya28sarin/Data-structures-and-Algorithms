#include<bits/stdc++.h>
using namespace std;


/* A binary tree node has data, pointer to left child  
and a pointer to right child */
class Node
{  
    public: 
    int data;  
    Node* left;  
    Node* right;  
}; 

Node* newNode(int data)  
{  
    Node* new_node = new Node(); 
    new_node->data = data;  
    new_node->left = NULL;  
    new_node->right = NULL;  
  
    return (new_node);  
}  

int search(int arr[], int strt, int end, int value)  
{  
    int i;  
    for (i = strt; i <= end; i++)  
    {  
        if (arr[i] == value)  
            return i;  
    }  
} 


Node* buildTree(int in[], int pre[], int start, int end, unordered_map<int,int> &mp);

Node* buldTreeWrap(int in[], int pre[], int len) 
{ 
    // Store indexes of all items so that we 
    // we can quickly find later

    unordered_map<int, int> mp; 
    for (int i = 0; i < len; i++) 
        mp[in[i]] = i; 
  
    return buildTree(in, pre, 0, len - 1, mp); 
} 

Node* buildTree(int in[], int pre[], int start, int end, unordered_map<int,int> &mp)
{
    static int index=0;

    if(start>end)
        return NULL;

    int curr=pre[index++];
    Node* new_node= newNode(curr);

    if(start==end)  
        return new_node;

    int in_index =mp[curr];
    new_node->left=buildTree(in,pre,start,in_index-1, mp);
    new_node->right=buildTree(in,pre,in_index+1,end,mp);

    return new_node;
}


void printInorder(Node* node)  
{  
    if (node == NULL)  
        return;  
  
    /* first recur on left child */
    printInorder(node->left);  
  
    /* then print the data of node */
    cout<<node->data<<" ";  
  
    /* now recur on right child */
    printInorder(node->right);  
}  
  

int main()
{
 int pre[] = {1,2,4,8,9,10,11,5,3,6,7 };  
    int in[] = {8,4,10,9,11,2,5,1,6,3,7};  
    int len = sizeof(in) / sizeof(in[0]);  

    Node* root = buldTreeWrap(in, pre, len);  
  
    /* Let us test the built tree by  
    printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";  
    printInorder(root);  
}