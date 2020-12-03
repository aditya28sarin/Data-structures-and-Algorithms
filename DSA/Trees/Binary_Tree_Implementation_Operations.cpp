#include<bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node *left;
	Node *right;
	
public:
	
	Node* createNode(int data);
	
	Node* insertNode(Node* root, int data);
	
	void levelOrder(Node* root);
	
	void preOrderRecursive(Node* root);
	
	void preOrderIterative(Node* root);
	
	void inOrderRecursive(Node* root);
	
	void inOrderIterative(Node* root);
	
	void postOrderRecursive(Node* root);
	
	void postOrderIterative(Node* root);
	
	Node* deleteNode(Node* root, int key);
	
	void reverseLevelOrder(Node* root);
	
	int treeHeight(Node* root);
	
	int findDiameter(Node* root, int max, int lh, int rh);
	
	int treeDiameter(Node* root);
	
	void mirrorTree(Node* root);
	
	bool checkBalanced(Node* root);
	
	int findMinimum(Node* root);
};	

//Creates a new node
Node* Node :: createNode(int key)
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
Node* Node :: insertNode(Node* root, int key)
{
	if(root==NULL)
	{
		return createNode(key);
	}
	
	queue <Node*> q;
	
	q.push(root);
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		if(temp->left)
		{
			q.push(temp->left);
		}
		else{
			temp->left=  createNode(key);
			return root;
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
		else{
			temp->right = createNode(key);
			return root;
		}
	}
}

//Level Order Traversal 
void Node :: levelOrder(Node* root)
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

//Preorder Traversal Recursive
void Node:: preOrderRecursive(Node* root)
{
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	
	preOrderRecursive(root->left);
	
	preOrderRecursive(root->right);
}


//Preorder Traversal Iterative
void Node:: preOrderIterative(Node* root)
{
		stack<Node *> st;
        while(1)
        {
            if(root!=NULL)
            {
                std::cout<<root->data<<" ";
                st.push(root);
                root=root->left;
            }
            else
            {
                if(!st.empty())
                {
                    root=st.top();
                    st.pop();
                    root=root->right;
                }
                else 
				{
					break;
				}
            }
        }
}

//Inorder Traversal Recursive
void Node:: inOrderRecursive(Node* root)
{
	if(root==NULL)
		return;
	
	inOrderRecursive(root->left);
	
	cout<<root->data<<" ";
	
	inOrderRecursive(root->right);
}

// Inorder Traversal Iterative 
void Node :: inOrderIterative(Node* root)
{
	std:: stack <Node*> st;
    while(1)
    {
        if(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            if(!st.empty())
            {
                root =st.top();
                cout<<root->data<<" ";
                st.pop();
                root=root->right;
            }
            else
            {
                break;
            }
            
        }
    }
}

//postorder Traversal Recursive
void Node:: postOrderRecursive(Node* root)
{
	if(root==NULL)
		return;
	
	postOrderRecursive(root->left);
	
	postOrderRecursive(root->right);

	cout<<root->data<<" ";
}

//postOrder Traversal Iterative
void Node:: postOrderIterative(Node* root)
{
	std::stack <Node*> st;

        while(1) { 
            if(root != NULL)
			{ 
                st.push(root); 
                st.push(root); 
                root = root->left; 
            } 
            else{
	
            if(st.empty())
                 return; 

            root = st.top();
            st.pop(); 
              
            if(!st.empty() && st.top() == root) 
                root = root->right; 
              
            else { 
                  
                cout<<root->data<<" ";
                root=NULL;
            } 
			}
            
        } 
}

//Delete Node in Tree

Node* Node :: deleteNode(Node* root, int key)
{
	if(root==NULL)
		return root;
		
	queue<Node*> q;
	q.push(root);
	
	Node* rightmost_node = root;
	Node* deleted_node = NULL;
	
	//level order to find the node to be deleted
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		if(temp->data==key)
		{
			deleted_node=temp;
		}
		
		if(temp->left)
			q.push(temp->left);
		
		if(temp->right)
			q.push(temp->right);
	}
	
	while(rightmost_node->right->right!=NULL)
	{
		rightmost_node=rightmost_node->right;
	}
	
	Node* extra = rightmost_node->right;
	rightmost_node->right=NULL;
	
	swap(extra->data, deleted_node->data);
	
	return root;
	
}


//Reverse Level Order Traversal 
void Node :: reverseLevelOrder(Node* root)
{
	if(root==NULL)
	return;
	
	queue<Node*> q;
	q.push(root);
	
	stack<Node*> st; 
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		st.push(temp);
		
		if(temp->right)
		{
			q.push(temp->right);
		}
		
		if(temp->left)
		{
			q.push(temp->left);
		}
	}
	
	while(!st.empty())
	{
	    cout<<st.top()->data<<" ";
	    st.pop();
	}	
}

// Height of Binary Tree
int Node::treeHeight(Node* root)
{
	if(root==NULL)
		return 0;

	return(max(treeHeight(root->left),treeHeight(root->right)))+1;
}

//Diameter of the tree 

int Node :: findDiameter(Node* root, int max, int lh, int rh)
{

    if(root->left==NULL && root->right==NULL)
        return max;
    
    if(root->left!=NULL)
        lh=treeHeight(root->left);
	
	if(root->right!=NULL)
	    rh=treeHeight(root->right);
	
	if((lh+rh +1)>max)
	    max=lh + rh + 1;
	
	 return findDiameter(root->left, max, lh, rh);
	
	return findDiameter(root->right, max, lh, rh);
	

}
int Node :: treeDiameter(Node* root)
{
    int i= findDiameter(root, 0, 0,0);
    return    i;
}


//Mirror of tree 
void Node :: mirrorTree(Node* root)
{
	if(root==NULL)
		return;

	mirrorTree(root->left);
	mirrorTree(root->right);
	
	Node* temp = root->left;
	root->left=root->right;
	root->right=temp;
}

//Check if Tree is Balanced
bool Node :: checkBalanced(Node* root)
{
    if(root==NULL)
        return true;
        
    if(abs(treeDiameter(root->left)-treeDiameter(root->right))<=1)
        return true;
    
    return false;
}

//Find Minimum and Maximum in Binary treeDiameter
int Node :: findMinimum(Node* root)
{
    int min = INT_MAX;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
     Node* temp = q.front();
     q.pop();
     
     if(temp->data<min)
        min=temp->data;
        
     if(temp->left)
        q.push(temp->left);
    
      if(temp->right)
        q.push(temp->right);
    }
    
    return min;
}

// Driver Code
int main() 
{ 

    Node n;
    Node* root = NULL; 
    root = n.insertNode(root, 50); 
     n.insertNode(root, 30); 
	 n.insertNode(root, 20); 
	 n.insertNode(root, 40); 
	 n.insertNode(root, 70); 
	 n.insertNode(root, 60); 
	 n.insertNode(root, 80); 
  
	cout<<"Level Order Traveral of tree:"<<endl;
    n.levelOrder(root); 
	
	cout<<"\nPre Order Traveral of tree (Recursive):"<<endl;
	n.preOrderRecursive(root); 
	
	cout<<"\nPre Order Traveral of tree (Iterative):"<<endl;
	n.preOrderIterative(root); 
	
	cout<<"\nIn Order Traveral of tree(Recursive):"<<endl;
	n.inOrderRecursive(root); 
	
	cout<<"\nIn Order Traveral of tree (Iterative):"<<endl;
	n.inOrderIterative(root); 
	
	cout<<"\nPost Order Traveral of tree (Recursive):"<<endl;
	n.postOrderRecursive(root); 
	
	cout<<"\nPost Order Traveral of tree (Iterative):"<<endl;
	n.postOrderIterative(root); 
	
	cout<<"\nReverse Level Order Traversal of tree:"<<endl;
    n.reverseLevelOrder(root);
	
	cout<<"\nHeight of tree:"<<endl;
    cout<<n.treeHeight(root);
	
	cout<<"\nTree Diameter:"<<endl;
    cout<<n.treeDiameter(root);
	
	cout<<"\nMirror of Tree:"<<endl;
    n.mirrorTree(root);
	n.levelOrder(root);
	
	n.deleteNode(root,30);
	cout<<"\nLevel Order Traveral of tree after deletion:"<<endl;
    n.levelOrder(root); 
	
    
    if(n.checkBalanced(root)==true)
        cout<<"\nTree is Balanced"<<endl;
    else
        
        cout<<"\nTree is not Balanced"<<endl;
        
    cout<<"\nMinimum of Binary Tree is:"<<endl;
    cout<<n.findMinimum(root);
	
	
	
    return 0; 
}

