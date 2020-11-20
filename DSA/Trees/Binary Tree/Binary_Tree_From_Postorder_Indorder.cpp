#include<bits/stdc++.h>
using namespace std; 
  
/* A binary tree node has data, pointer to left 
   child and a pointer to right child */
class Node { 
    public:
    int data; 
    Node *left, *right; 
}; 
  
/* Function to find index of value in arr[start...end] 
   The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 
  
/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
    Node* node = new Node();
        node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  

Node* buildTreeUtil(int in[], int post[], int start, int end, int *index, unordered_map<int,int> mp)
{

    if(start>end)
        return NULL;
    int curr=post[(*index)--];
    Node* new_node = newNode(curr);
 

    if(start==end)
        return new_node;

    int in_index= mp[curr];
    
    new_node->right = buildTreeUtil(in, post,in_index+1, end , index, mp);
    
    new_node->left = buildTreeUtil(in, post,start, in_index-1, index, mp);
    
    return new_node;
}


Node* buildTree(int in[], int post[], int n)
{
    int index=n-1;

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        mp[in[i]]=i;
    }
    return buildTreeUtil(in,post,0,n-1, &index,mp); 
}

/* This funtcion is here just to test  */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int main() 
{ 
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n = sizeof(in) / sizeof(in[0]); 
  
    Node* root = buildTree(in, post, n); 
  
    cout << "Preorder of the constructed tree : \n"; 
    preOrder(root); 
  
    return 0; 
}   