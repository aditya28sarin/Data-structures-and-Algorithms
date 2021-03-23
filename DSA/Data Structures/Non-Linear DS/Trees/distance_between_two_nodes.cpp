// URL: https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 

 int findLevel(Node *root, Node* node, int level)
{
    if (root == nullptr)
        return INT_MIN;
 
    if (root == node)
        return level;
 
    int left = findLevel(root->left, node, level + 1);
 
    if (left != INT_MIN)
        return left;
 
    return findLevel(root->right, node, level + 1);
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


int findDist(Node* root, Node* x, Node* y)
{
	Node* lca=findLCA(root,x->data,y->data);


	return findLevel(lca,x,0) + findLevel(lca,y,0); 
	// above return statement is equivalent to
    // findLevel(root, x, 0) + findLevel(root, y, 0) - 2*findLevel(root, lca, 0)
 
}


int main()
{
    Node* root = NULL;
 
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right->right = new Node(8);
 
    // find distance between node 7 and node 6
    cout <<findDist(root, root->right->left->left, root->right->right);
 
    return 0;
}