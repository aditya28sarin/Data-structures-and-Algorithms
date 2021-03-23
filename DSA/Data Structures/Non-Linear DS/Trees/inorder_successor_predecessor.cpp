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


void inorderPreSuc(Node* root, int key, Node* &pre, Node* &suc){

	if(root==NULL){
		return;
	}

	if(root->data == key){

		if(root->left){
			Node* temp = root->left;
			while(temp->right){
				temp=temp->right;
			}
			pre=temp;
		}

		if(root->right){
			Node* temp = root->right;
			while(temp->left){
				temp=temp->left;
			}
			suc=temp;
		}

		return;
	}


	if(key<root->data){
		suc=root;
		return inorderPreSuc(root->left, key, pre,suc);
	}

	else{
		pre=root;
		return inorderPreSuc(root->right, key, pre,suc);
	}
}

int main() 
{ 
    Node *root = NULL; 
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
	int key = 65;

	Node* pre = NULL, *suc = NULL;
 
    inorderPreSuc(root, key, pre, suc);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
   
    
    return 0; 
} 