#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

};

// Preorder (Recursion)
void printPreorder(Node* root)
{
    if(root!=NULL)
    {
        std::cout<<root->data<<" ";

        printPreorder(root->left);

        printPreorder(root->right);
    }
}

// Iterative Preorder
void iterativePreOrderTraversal(Node* root)
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
                else break;
            }
        }
}

// Inorder (Recursion)
void printInorder(Node* root)
{
    if(root!=NULL)
    {
        printInorder(root->left);

        cout<<root->data<<" ";

        printInorder(root->right);
    }
}

// Iterative InOrder
void iterativeInOrderTraversal(Node* root)
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

// Postorder (Recursion)
void printPostorder(Node* root)
{
    if(root!=NULL)
    {
        printPostorder(root->left);

        printPostorder(root->right);

        cout<<root->data<<" ";
    }
}

//iterative postOrder With 2 stacks
void iterativePostOrderTraversal(Node* root)
{
    std::stack <Node*> st1;
    
    std::stack <Node*> st2;

    //Node* temp = root;

    st1.push(root);

    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left!=NULL)
            st1.push(root->left);
        
        if(root->right!=NULL)
            st1.push(root->right);
    }

    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

//Iterative Postorder with 1 stack 
void singleStackPostorder(Node* root)
{
     std::stack <Node*> st;

        while(1) { 
            while(root != NULL)
             { 
                st.push(root); 
                st.push(root); 
                root = root->left; 
            } 
              
            // Check for empty stack 
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


//level order traversal 
void printLevelOrder(Node* root)
{
    std:queue <Node*> q1;
        
    q1.push(root);

    if(root==NULL)
        return;
    while(!q1.empty())
    {
        Node* curr=q1.front();
        cout<<curr->data<<" ";

        if(curr->left!=NULL)
            q1.push(curr->left);

        if(curr->right!=NULL)
            q1.push(curr->right);

            q1.pop();
    }

}

int main()
{
    Node* root =new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root);

    cout << "\n Iterative Preorder traversal of binary tree is \n"; 
    iterativePreOrderTraversal(root);
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  

    cout << "\nIterative Inorder traversal of binary tree is \n"; 
    iterativeInOrderTraversal(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 

     cout << "\n Iterative Postorder traversal (Using 2 Stacks) of binary tree is \n"; 
    iterativePostOrderTraversal(root);

     cout << "\n Iterative Postorder traversal (Using 1 Stack) of binary tree is \n"; 
    singleStackPostorder(root);

    cout << "\nLevelOrder traversal of binary tree is \n"; 
    printLevelOrder(root); 
  
    return 0; 

}