#include<bits/stdc++.h>
using namespace std;


class node  
{  
    public: 
    int data;  
    node *left;  
    node *right;  
};  
  
node* newNode (int data)  
{  
    node* temp = new node(); 
  
    temp->data = data;  
    temp->left = temp->right = NULL;  
  
    return temp;  
}  
  
// O(n^2) Time complexity 
node* constructTreeUtil(int pre[], int size, int start, int end, int *index)
{
    if((*index)>=size || start>end)
        return NULL;

    int curr= pre[(*index)];
    node* new_node = newNode(curr);
    (*index)++;


    if(start==end)
        return new_node;


    int i;
    for(i=start;i<=end;i++)
    {
        if(pre[i]>new_node->data)
            break;
    }

    new_node->left= constructTreeUtil(pre, size, *index, i-1,index);
    new_node->right= constructTreeUtil(pre, size, i, end,index);

    return new_node;
}


node* constructTree(int pre[], int size)
{
    int index=0;
    return constructTreeUtil(pre,size, 0,size-1, &index);
}

// O(n) Time complexity 

node* constructTreeUtil1(int pre[], int key, int min, int max, int* index, int size)
{
    if((*index)>=size)
        return NULL;

    node*  new_node=NULL;

    if(key>min && key< max )
    {
    
        new_node = newNode(key);
        (*index)++;


        if((*index)<size)
        {
            new_node->left = constructTreeUtil1(pre, pre[*index],min,key, index, size);
            new_node->right = constructTreeUtil1(pre, pre[*index], key, max, index, size);
            
        }
    }
    return new_node;
}

node* constructTree1(int pre[], int size )
{
    int index=0;

    return constructTreeUtil1(pre,pre[0], INT_MIN, INT_MAX,&index, size);
}



//driver code 
void printInorder (node* node)  
{  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout<<node->data<<" ";  
    printInorder(node->right);  
}  
  
int main ()  
{  
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    node *root = constructTree(pre, size);  
  
    cout<<"Inorder traversal of the constructed tree O(n^2): \n";  
    printInorder(root);  
  

    node *root1 = constructTree1(pre, size);  
  
    cout<<"\n\nInorder traversal of the constructed tree O(n): \n";  
    printInorder(root1);  
  
    return 0;  
}  