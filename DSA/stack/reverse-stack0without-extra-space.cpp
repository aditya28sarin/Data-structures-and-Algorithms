#include<bits/stdc++.h>
using namespace std;

class stackNode{

public:
    int data;
    stackNode* next;

    stackNode(int data)
    {
        data ==data;
        next=NULL;
    }
};



class Stack{

public:
    stackNode* head;

    void push(int data)
    {
        if(head==NULL)
        {
            head=new stackNode(data);
            return;
        }
        
        stackNode* s =new stackNode(data);
        s->next=head;
        head=s;
    }

    stackNode* pop()
    {   
        stackNode
    }

};
