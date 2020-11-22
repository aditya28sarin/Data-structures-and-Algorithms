#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node()
    {
        data=0;
        *left=NULL;
        *right=NULL;
    }
    Node(int data)
    {
        data=data;
        left=NULL;
        right=NULL;
    }
};


int main()
{
    //create root node

    Node *root = new Node(1);


    /* following is the tree after above statement  
  
        1 
    / \ 
    NULL NULL  
*/

    root->left=new Node(2);
    root->right= new Node(3);


    /* 2 and 3 become left and right children of 1 
        1 
        / \ 
        2  3 
      / \ / \ 
    NULL NULL NULL NULL 
*/

    root->left->left= new Node(4);


    /* 4 becomes left child of 2 
        1 
    /     \ 
    2       3 
    / \    / \ 
   4 NULL NULL NULL 
  / \ 
NULL NULL 
*/
  
}




//implementation 2

// #include<stdio.h> 
// #include<stdlib.h> 
// struct node  
// { 
//     int data; 
//     struct node *left; 
//     struct node *right; 
// }; 
  
// /* newNode() allocates a new node with the given data and NULL left and  
// right pointers. */
// struct node* newNode(int data) 
// { 
  
// struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
// node->data = data; 
   
// node->left = NULL; 
// node->right = NULL; 
// return(node); 
// } 
  
  
// int main() 
// { 
// /*create root*/
// struct node *root = newNode(1);  
// /* following is the tree after above statement  
  
//         1 
//     / \ 
//     NULL NULL  
// */
  
  
// root->left     = newNode(2); 
// root->right     = newNode(3); 
// /* 2 and 3 become left and right children of 1 
//         1 
//         / \ 
//         2     3 
//     / \ / \ 
//     NULL NULL NULL NULL 
// */
  
  
// root->left->left = newNode(4); 
// /* 4 becomes left child of 2 
//         1 
//     /     \ 
//     2         3 
//     / \     / \ 
// 4 NULL NULL NULL 
// / \ 
// NULL NULL 
// */
  
// getchar(); 
// return 0; 
// } 