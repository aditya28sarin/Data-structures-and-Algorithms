#include<iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node* prev;
    Node* next;


    Node()
    {
        key=0;
        data=0;
        prev=NULL;
        next=NULL;
    }

    Node(int k, int d)
    {
     key=k;
     data=d;
     prev=NULL;
     next=NULL;
    }

};


class DoublyLinkedList{

public:
    Node* head;

    DoublyLinkedList()
    {
        head=NULL;
    }
    DoublyLinkedList(Node* n)
    {
        head=n;
    }


    ///1. Check if node exists using key value

    Node* checkIfNodeExists(int k)
    {
        Node* temp =NULL;
        Node* ptr=head;

        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    ///2. Append a Node to the list
    void AppendNode(Node* n)
    {
        //check if node exists
        if(checkIfNodeExists(n->key)!=NULL)
        {
            cout<<"Node Already Exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node Appended"<<endl;
            }
            else
            {
                Node* ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node Appended"<<endl;
            }
        }
    }

    ///3. Prepend Node

    void PrependNode(Node* n)
    {
        //check if node exists
        if(checkIfNodeExists(n->key)!=NULL)
        {
            cout<<"Node Already Exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node Appended"<<endl;
            }
            else
            {
            head->prev=n;
            n->next=head;
            head=n;
            cout<<"Node Prepended"<<endl;
            }
        }
    }

    ///4. Insert a node in between

    void InsertNodeAfter(int k, Node* n)
    {
        Node* ptr =checkIfNodeExists(k);

        if(ptr==NULL)
        {
            cout<<"No Node exists"<<endl;
        }
        else
        {
            if(checkIfNodeExists(n->data)!=NULL)
            {
                cout<<"Node already exists"<<endl;
            }
            else
            {
                Node* nextNode=ptr->next;
                //Inserting at the end
                if(nextNode==NULL)
                {
                    ptr->next=n;
                    n->prev=ptr;
                    cout<<"Node Inserted at the end"<<endl;
                }
                //Inserting node in between
                else
                {
                    nextNode->prev=n;
                    n->next=nextNode;
                    n->prev=ptr;
                    ptr->next=n;
                    cout<<"Node inserted in between"<<endl;
                }
            }
        }
    }

    //5. Deleting a Node

    void deleteNodeByKey(int k)
    {
        Node* ptr = checkIfNodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No node there to delete"<<endl;
        }
        else
        {
            if(head->key==k)
            {
                head=head->next;
                cout<<"Head Node Unlinked"<<endl;
            }
            else
            {
                Node* prevNode=ptr->prev;
                Node* nextNode=ptr->next;

                if(nextNode==NULL)
                {
                    prevNode->next=NULL;
                    cout<<"Node Deleted"<<endl;
                }
                else
                {
                    prevNode->next=nextNode;
                    nextNode->prev=prevNode;
                    cout<<"Node deleted"<<endl;
                }
            }
        }
    }

    ///7. Update Node
    void updateNodeByKey(int k, int d)
    {
        Node* ptr=checkIfNodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data=d;
            cout<<"Node Data Updated Successfully"<<endl;
        }
        else
        {
            cout<<"Node Does not exist"<<endl;
        }
    }

    ///7. Print List
    void PrintList()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node* temp =head;
            while(temp!=NULL)
            {
                cout<<temp->key<<temp->data<<endl;
                temp=temp->next;
            }
        }

    }
};
