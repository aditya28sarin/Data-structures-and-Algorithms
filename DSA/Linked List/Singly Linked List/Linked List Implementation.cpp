#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node* next;

    Node()
    {
        data=0;
        key=0;
        next=NULL;
    }

    Node(int d, int k)
    {
        d=data;
        k=key;
    }
};

class SinglyLinkedList
{
public:
    Node* head;

    SinglyLinkedList()
    {
        head=NULL;
    }
    SinglyLinkedList(Node* n)
    {
        head=n;
    }
    ///Check if node exists or not
    Node* nodeExists(int k)
    {

        Node* temp=NULL;

        Node* ptr= head;

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

    ///Append Node

    void appendNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
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
                Node* ptr =head;

                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node Appended"<<endl;
            }
        }
    }


    ///Prepend node

    void prependNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node Already Exists"<<endl;
        }
        else
        {
            n->next=head;
            head=n;
            cout<<"Node Appended"<<endl;
        }
    }

    ///Insert after particular node

    void insertNodeAfter(int k, Node* n)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No node exists with k"<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node already exists"<<endl;
            }
            else
            {
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node Inserted"<<endl;
            }
        }
    }

    ///Delete Node

    void deleteNodeByKey(int k)
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key=k)
            {
                head=head->next;
                cout<<"Node Unlinked"<<endl;
            }
            else
            {
                Node* temp =NULL;
                Node* prevptr =head;
                Node* currentptr=head->next;

                while(currentptr!=NULL)
                {
                    if(currentptr->key=k)
                    {
                        temp=currentptr;
                        currentptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        currentptr=currentptr->next;
                    }
                }

                if(temp!=NULL)
                {
                    prevptr->next=temp->next;
                    cout<<"Node Unlinked"<<endl;
                }
                else
                {
                    cout<<"Node does not have a value with given key"<<endl;
                }

            }
        }
    }


     void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  /// printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }

  }

};


int main() {

  SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node(); // this creates dynamic memory allocation on the heap instead of the stack
                            // an object is created of node type in the heap and n1 is the pointer to that object

    //we can either use as above or else as below:
    //Node n1;
    //n1.key=....
    //But in the second method the memory is allocated in the stack memory and hence for the case of new the memory is allocated on the heap
    // and hence it is global and available throughout the program.

    //in the second implementation when the switch case runs over and over again, the n created by second method will be destroyed once is run is over and hence we save it in the heap.

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1); // n1 is a pointer and hence we do not need to use & sign here, even if wwe are passing by pass by pointer/address.
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
