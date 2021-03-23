#include<bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
class Node
{
public:
     Node *left, *right;
    int data;
};
 

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}
 

Node* findLCA(Node* root, int a, int b)
{
	if(root==NULL)
		return NULL;

	if(root->data==a || root->data==b)
		return root;


	Node* left= findLCA(root->left,a,b);
	Node* right= findLCA(root->right,a,b);

	if(left!=NULL && right!=NULL)
		return root;

	return (left!=NULL?left:right);
}

int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data<<endl;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->data<<endl;
    cout << "nLCA(3, 4) = " << findLCA(root, 1, 8)->data<<endl;
    cout << "nLCA(2, 4) = " << findLCA(root, 6,8)->data<<endl;
    return 0;
}