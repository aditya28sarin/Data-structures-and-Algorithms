#include<bits/stdc++.h>
using namespace std;

char tree[10];


int root(char val){
    if(tree[0]!='\0'){
        cout<<"Root is already present!";
    }else{
        tree[0]=val;
    }
    return 0;
}

int set_left(char val, int parent){
    if(tree[parent]=='\0'){
        cout<<"cannot set child of NULL";
    }else{
        tree[parent*2+1]=val;
    }
    
    return 0;
}

int set_right(char val, int parent){
    if(tree[parent]=='\0'){
        cout<<"cannot set child of NULL";
    }else{
        tree[parent*2+2]=val;
    }
    
    return 0;
}


int print_tree()
{
    cout << "\n";
    for(int i = 0; i < 10; i++)
    {
        if(tree[i] != '\0')
            cout << tree[i];
        else
            cout << "-";
    }
    return 0;
}

int main(){
    root('A');
    //insert_left('B',0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);
    print_tree();
    return 0;
}