#include<bits/stdc++.h>
using namespace std;
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
node* newnode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}


void printArray(int ints[], int len)  
{  
    int i;  
    for (i = 0; i < len; i++)  
    {  
        cout << ints[i] << " ";  
    }  
    cout<<endl;  
}    

void printPaths(node* root);
void printPathsUtil(node* root, int arr[], int index);

void printPaths(node* root)
{
	int arr[1000];
	printPathsUtil(root,arr,0);
} 

void printPathsUtil(node* root, int arr[], int index)
{
	if(root==NULL)
		return;
	
	arr[index]=root->data;
	index++;
	
	if(root->left==NULL && root->right==NULL)
	{
		printArray(arr,index);
	}
	else
	{
		printPathsUtil(root->left, arr, index);
		printPathsUtil(root->right, arr, index);
	}
}

  
int main()  
{  

    node *root = newnode(10);  
    root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);  
    root->right->left = newnode(2);  
      
    printPaths(root);  
    return 0;  
}  
  