#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};


//creating a new node in a BST
Node* newNode(int item)
{
    Node* new_node=new Node();
    new_node->data=item;
    new_node->left=new_node->right=NULL;
    return new_node;
}

Node* insert(Node* root, int key)
{
    if(root==NULL)
        return newNode(key);
    
    if(key<=root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);

    return root;
}


void inorderPreSuc(Node* root, int key, int &pre, int &suc)
{
	if(root==NULL)
		return;
	
	if(root->data==key)
	{
		if(root->left!=NULL)
		{
			Node* temp=root->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			pre=temp->data;
		}
		
		if(root->right!=NULL)
		{
			Node* temp=root->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			suc=temp->data;
		}
		return;
	}
	
	if(key<root->data)
	{
		suc=root->data;
		inorderPreSuc(root->left,key,pre,suc);
	}
	else
	{
		pre=root->data;
		inorderPreSuc(root->right,key,pre,suc);
	}
	
}

int main() 
{ 
    Node *root = NULL; 
    root = insert(root, 50);
    root =  insert(root, 30); 
    root =  insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
    root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 62); 
    root = insert(root, 79); 
	int key = 40;
	int pre=-1,suc=-1;
	inorderPreSuc(root,key,pre,suc);
	cout<<"Inorder Predecessor of "<<key<<" is:"<<pre<<endl;
	cout<<"Inorder Successor of "<<key<<" is:"<<suc<<endl;
   
    
    return 0; 
} 