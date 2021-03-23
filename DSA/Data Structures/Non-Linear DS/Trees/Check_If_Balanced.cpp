#include<bits/stdc++.h>
using namespace std;

class Node{
		
public:
	int data;
	Node *left;
	Node *right;
};	

//Creates a new node
Node* createNode(int key)
{
	Node* newNode = new Node();
	
	if(newNode==NULL){
		cout << "Memory error\n";
        return NULL;
	}
	
	newNode -> data = key;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	return newNode;
}



//Inserts Node in Tree
Node* insertNode(Node* root, int key)
{
	if(root==NULL){
		return createNode(key);
	}	
	queue <Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->left){
			q.push(temp->left);
		}else{
			temp->left=  createNode(key);
			return root;
		}
		if(temp->right){
			q.push(temp->right);
		}else{
			temp->right = createNode(key);
			return root;
		}
	}
}

//level order traversal 
void levelOrder(Node* root){
	if(root==NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left){
			q.push(temp->left);
		}if(temp->right){
			q.push(temp->right);
		}
	}	
	cout<<endl;
}


int height(Node* root){
	if (root == NULL) 
        return 0; 
	return (max(height(root->left),height(root->right)))+1;
}

bool checkIfBalanced(Node* root){

    int lh,rh;

    if(root==NULL){
        return 1;
    }

    lh = height(root->left);
    rh = height(root->right);

    if(abs(rh-lh)>=1 && checkIfBalanced(root->left) && checkIfBalanced(root->right));
        return 1;

    return 0;

}


// Driver Code
int main() 
{ 

    Node n;
    Node* root = NULL; 
    root = insertNode(root, 50); 
     insertNode(root, 30); 
	 levelOrder(root);
	 insertNode(root, 20); 
	 levelOrder(root);
	 insertNode(root, 40);
	 levelOrder(root); 
	 insertNode(root, 70);
	 levelOrder(root); 
	 insertNode(root, 60);
	 levelOrder(root); 
	 insertNode(root, 80);
	 levelOrder(root); 
	cout<<endl;
	 cout<<height(root);

     if(checkIfBalanced(root)){
         cout<<"Tree is balanced!"<<endl;
     }else{
         cout<<"Tree is not balanced"<<endl;
     }

    return 0; 
}

