import java.io.*;

public class LinkedList { 
    
    Node head;
    
    public static class Node{
        int data;
        Node next;


        Node(int d){
            this.data=d;
            next=null;
        }
    }


    // Insert Node at the end of Linked List
    public static LinkedList insert(LinkedList list, int data){

        Node newNode = new Node(data);

        if(list.head == null){
            list.head = newNode;
        }

        else { 

            Node last = list.head;

            while(last.next != null){
                last=last.next;
            }

            last.next=newNode;
        }

        return list;
    }

    //Print Linked List
    public static void printList(LinkedList list){
        Node currNode = list.head;

        while(currNode != null){
            System.out.print(currNode.data + " ");

            currNode = currNode.next;
        }

        System.out.println();
    }

    //Deletion By Key
    public static LinkedList deleteByKey(LinkedList list, int key){
        
        Node currNode = list.head;
        Node prevNode = null;


       if(currNode != null && currNode.data == key){
           list.head=currNode.next;

            System.out.println(key + " found and deleted");

            return list;
       } 


       while(currNode.data != key && currNode!=null){
            prevNode = currNode;
            currNode=currNode.next;
       }

       if(currNode != null){
           prevNode.next=currNode.next;
            
           System.out.println(key + " found and deleted");

       }
        

       if(currNode==null){
            System.out.println(key + " not found");
       }


        return list;   
    }



    // Main Function
    public static void main(String args[]){
        LinkedList lst = new LinkedList();


        lst=insert(lst, 1);
        lst=insert(lst, 2);
        lst=insert(lst, 3);
        lst=insert(lst, 4);
        printList(lst);
        lst=insert(lst, 5);
        lst=insert(lst, 6);
        lst=insert(lst, 7);
        printList(lst);

        lst = deleteByKey(lst, 5);
        printList(lst);

        lst = deleteByKey(lst, 1);
        printList(lst);

        lst = deleteByKey(lst, 12);
        printList(lst);
    }

}