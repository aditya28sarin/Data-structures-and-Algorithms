// URL: https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class Node 
{ 
public:
    int data; 
    Node *left, *right; 
}; 


Node* getNode(int data) 
{ 
    Node *newNode = new Node; 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 


void printPath(Node* root, int x, vector<int> &path)
{

	vector<int> vt;

	if(root==NULL)
		return;

	path.push_back(root->data);


	if(root->data==x)
	{
		return;
	}
	
	if(root->left)
	{
		printPath(root->left,x, path);
	}

	if(root->right)
	{
		printPath(root->right,x, path);
	}

	path.pop_back(); 
}

int main() 
{ 
    Node *root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->right->left->left = getNode(8); 
    root->right->right->right = getNode(9); 
          
    int x = 9; 
    vector<int> vt;
    printPath(root, x,vt);

    for(int i=0;i<4;i++){
    	cout<<vt[i]<<" ";
    } 

    return 0; 
} 