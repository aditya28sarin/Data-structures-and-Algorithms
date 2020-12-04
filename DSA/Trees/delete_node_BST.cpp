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

void levelOrder(Node* root)
{
	if(root==NULL)
		return;
	
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		cout<<temp->data<<" ";
		
		if(temp->left)
		{
			q.push(temp->left);
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
	}	
}

Node* minNode(Node* root);
Node* deleteNode(Node* root, int key)
{
	if(root==NULL)
		return root;
	
	else if(key<root->data)
		root->left=deleteNode(root->left,key);
	
	else if(key>root->data)
		root->right=deleteNode(root->right,key);
	
	if(key==root->data)
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		
		}
		
		else if(root->left==NULL)
		{
			Node* temp =root;
			root=root->right;
			delete temp;
		
		}
		
		else if(root->right==NULL)
		{
			Node* temp =root;
			root=root->left;
			delete temp;
			
		}
		else
		{
			Node* temp = minNode(root->right);
			root->data=temp->data;
			root->right = deleteNode(root->right, temp->data);
		
		}
		
	}
	return root;
		
}

Node* minNode(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}



int main() 
{ 
    Node *root = NULL; 
    root = insert(root, 50);
    root =  insert(root, 30); 
    root =  insert(root, 70); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 45); 
    root = insert(root, 49); 
    root = insert(root, 60); 
    root = insert(root,	80);  
	int key = 30;
	
	cout<<"Levelorder before deleting: "<<endl;
	levelOrder(root);
	deleteNode(root,key);
	cout<<"\nLevelorder after deleting: "<<endl;
	levelOrder(root);
   
    
    return 0; 
} 