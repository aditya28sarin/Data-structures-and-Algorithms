#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

//Preorder -> O(n^2) solution
class Solution {
public:
    
    TreeNode* BSTUtil(TreeNode* &root, int element){
        if(!root){
            return root = new TreeNode(element);
        }
        
        if(root->val > element){
            root->left = BSTUtil(root->left, element);
        }else{
            root->right = BSTUtil(root->right, element);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        
        for(auto x:preorder){
            BSTUtil(root,x);
        }
        
        return root;
    }
};


// Preorder -> O(n) solution
Node* BSTFromPreOptimizedUtil(int pre[], int *preIndex, int key, int min, int max, int size){
    
    if (*preIndex >= size)
        return NULL;
 
    Node* root= NULL;


    if(key>min && key<max){
        root = newNode(key);
        *preIndex =*preIndex + 1;

        if(*preIndex < size){
            root->left = BSTFromPreOptimizedUtil(pre,preIndex, pre[*preIndex], min, key, size);
            root->right = BSTFromPreOptimizedUtil(pre,preIndex, pre[*preIndex], key, max, size);
        }
    }
    return root;
}

Node* BSTFromPreOptimized(int pre[], int size)
{
    int preIndex = 0;
    return BSTFromPreOptimizedUtil(pre, &preIndex, pre[0],INT_MIN, INT_MAX, size);
}

//Posorder -> O(n)
Node* BSTFromPostUtil(int post[], int *postIndex, int key, int min, int max, int size){
    if (*postIndex < 0) 
        return NULL; 

    Node* root = NULL;

    if(key>min && key< max){
        root = newNode(key);
        *postIndex = *postIndex - 1;

        if(*postIndex>=0){
            root->right = BSTFromPostUtil(post, postIndex, post[*postIndex], key, max, size);

            root->left = BSTFromPostUtil(post, postIndex, post[*postIndex], min, key, size);
        }
    }
    return root;
}

Node* BSTFromPost(int post[], int size){

    int postIndex = size-1;

    return BSTFromPostUtil(post, &postIndex, post[postIndex], INT_MIN, INT_MAX, size);
}


void printInorder(Node* root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);

    Node* root = BSTFromPre(pre,size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    Node* root1 = BSTFromPreOptimized(pre,size);

    cout << "\nInorder traversal of the constructed tree: \n";
    printInorder(root1);

    int post[] = {1, 7, 5, 50, 40, 10}; 
    int size1 = sizeof(post) / sizeof(post[0]); 

    Node* root2 = BSTFromPost(post, size1); 
  
    cout << "\nInorder traversal of "
        << "the constructed tree: \n"; 
    printInorder(root2); 
}