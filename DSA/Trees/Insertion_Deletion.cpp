#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node()
    {
        left=NULL;
        right=NULL;
        data=0;
    }
    Node(int key)
    {
        data=key;
        left=NULL;
        right=NULL;
    }
};


void inorder(Node* root)
{
    if(root==NULL)  
        return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

//insert a key in BT
void insert(Node* root, int key)
{
    Node* temp =NULL;

    queue <Node*> q;

    q.push(root);

     while(!q.empty())
     {
         temp=q.front();
         q.pop();


         if(temp->left==NULL)
         {
            temp->left=new Node(key);
            break;
         }
        else
            q.push(temp->left);
        
        if(temp->right==NULL)
        {
            temp->right=new Node(key);
            break;
        }

        else
            q.push(temp->right);
     }
}


//delete key from BT

void deepestDelete(Node* root, Node* delNode)
{
    queue <Node*> q2;
    q2.push(root);
    Node* temp=NULL;

    while(!q2.empty())
    {
        temp=q2.front();
        q2.pop();

        if(temp==delNode)
        {
            temp=NULL;
            delete(delNode);
            return;
        }

        if(temp->right)
        {
            if(temp->right==delNode)
            {
                temp->right=NULL;
                delete(delNode);
                return;
            }
            else
            {
                q2.push(temp->right);
            }
        }

        if(temp->left)
        {
            if(temp->left==delNode)
            {
                temp->left=NULL;
                delete(delNode);
                return;
            }
            else
            {
                q2.push(temp->left);
            }
            
        }
    }
}



Node* deletion(Node* root, int key)
{
    //if the tree is empty 
    if(root==NULL)
        return NULL;
        
    //if the node to be deleted is a leaf
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==key)
            return NULL;
        else
            return root;
    }

    queue <Node*> q1;
    q1.push(root);

    Node* temp=NULL;
    Node* key_node=NULL;

    while(!q1.empty())
    {
        temp=q1.front();
        q1.pop();


        if(temp->data==key)
            key_node=temp;

        if(temp->left)
            q1.push(temp->left);

        if(temp->right)
            q1.push(temp->right);
    }

    if(key_node!=NULL)
    {
        int x=temp->data;
        deepestDelete(root,temp);
        key_node->data=x;
    }
    return root;
}

int main()
{
    Node* root= new Node(10);
    root->left=new Node(11);
    root->left->left=new Node(7);
    root->right=new Node(9);
    root->right->left=new Node(15);
    root->right->right=new Node(8);

    cout << "Inorder traversal before deletion : "; 
    inorder(root); 

    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root);


     int key1 = 11; 
    root = deletion(root, key1); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
     
}