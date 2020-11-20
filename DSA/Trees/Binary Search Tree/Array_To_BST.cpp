#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int key)
{
    Node* new_node=new Node();
    new_node->data=key;
    new_node->left=NULL;
    new_node->right=NULL;
    
    return new_node;
}

Node* insert(vector<int> vt, int low, int high)
{
    if(low>high)
        return NULL;
        
    int mid = (low+high)/2;
    
    Node* root=createNode(vt[mid]);
        
    root->left=insert(vt,low,mid-1);
    
    root->right=insert(vt,mid+1,high);
        
    return root;
}

void preorder(Node* root)
{
    if(root==NULL)
        return;
        
    cout<<root->data<<" ";
    
    preorder(root->left);
    
    preorder(root->right);
}


int main() {
    int cases;
    
    cin>>cases;
    
    while(cases--)
    {
        int n;
        cin>>n;
        
        Node* root=NULL;
        
        vector<int> vt;
        int val;
        
        for(int i=0;i<n;i++)
        {
            cin>>val;
            vt.push_back(val);
        }
        
        sort(vt.begin(),vt.end());
       
        root=insert(vt,0,n-1);
        
        preorder(root);
        
        cout<<endl;
        
    }
	return 0;
}