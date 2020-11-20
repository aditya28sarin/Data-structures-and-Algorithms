#include<bits/stdc++.h>
using namespace std;

int arr[10];


int* set_parent(int key)
{
    if(arr[0]!='\0')
        cout<<"Tree already has a root"<<endl;
    else
    {
        arr[0]=key;
    }
    return arr;   
}


int* set_left( int parent, int key)
{
    if(arr[0]=='\0')
        cout<<"Cannot insert a child here as no root"<<endl;
    
    else
    {
        arr[2*parent+1]=key;
    }
    
    return arr;
}


int* set_right( int parent, int key)
{
    if(arr[0]=='\0')
        cout<<"Cannot insert a child here as no root"<<endl;
    
    else
    {
        arr[2*parent+2]=key;
    } 

    return arr;
}


void print_tree()
{
    for(int i=0;i<10;i++)
    {
        if(arr[i]!='\0')
        cout<<arr[i]<<" ";
       else
       {
           cout<<'-';
       }
    }
}


int main()
{
    set_parent(1);
    set_left(0,2);
    set_right(0,3);
    set_parent(2);
    set_left(1,4);
    set_right(1,5);
    set_parent(3);
    
    set_left(2,6);
    set_right(2,7);
    
    print_tree();
}