// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node *next;

    Node (int x)
  {
    data = x;
    next = NULL;
  }

};

void
printlist (Node * head)
{
  if (head == NULL)
    return;
  while (head != NULL)
    {
      cout << head->data << " ";
      head = head->next;
    }
  cout << endl;
}

void
append (struct Node **headRef, char data)
{
  struct Node *new_node = new Node (data);
  struct Node *last = *headRef;

  if (*headRef == NULL)
    {
      *headRef = new_node;
      return;
    }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

// task is to complete this function
struct Node *arrange (Node * head);

int
main ()
{
  int T;
  cin >> T;
  while (T--)
    {
      int n;
      char tmp;
      struct Node *head = NULL;
      cin >> n;
      while (n--)
	{
	  cin >> tmp;
	  append (&head, tmp);
	}
      head = arrange (head);
      printlist (head);
    }
  return 0;
}

// } Driver Code Ends


void swap (char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

struct Node *
arrange (Node * head)
{
  Node *comPtr = head;
  Node *temp = head;
  Node *ptr = NULL;
  set < char >st;

  st.insert ('a');
  st.insert ('e');
  st.insert ('i');
  st.insert ('o');
  st.insert ('u');



  while (temp ->next!= NULL)
    {
        
        
    
        if(st.find (comPtr->data) != st.end () && st.find (temp->next->data) != st.end ())
        {
           
           if(comPtr->data)
            char d=temp->next->data;
            temp->next=temp->next->next;
            
            Node* new_node = new Node(d);
            
            new_node->next=comPtr->next;
            
            comPtr ->next=new_node;
        }
    
        
      if(st.find (comPtr->next->data) != st.end ())
      {
          comPtr=comPtr->next;
      }
      if(temp->next==NULL)
        break;
      if(st.find(temp->next->data)==st.end() && temp->next!=NULL)
      {
          temp=temp->next;
      }
      
	}

    return head;

    }
