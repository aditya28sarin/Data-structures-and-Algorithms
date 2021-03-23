#include <bits/stdc++.h>
using namespace std;
 
// Tree node
class Node
{
public:
    int data;
    Node *left, *right;
};


Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void diagonalPrintUtil(Node* root, int vd, map<int,vector<int>> &mp)
{
    if(root==NULL)
        return;
        
    mp[vd].push_back(root->data);
    
    diagonalPrintUtil(root->left,vd+1,mp);
    
    diagonalPrintUtil(root->right,vd,mp);
    
}


void diagonalPrint(Node* root)
{
	map<int, vector<int>> mp;

	diagonalPrintUtil(root,0,mp);
	
	cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :mp)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }


}

int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 

    diagonalPrint(root);
 
    return 0;
}
 