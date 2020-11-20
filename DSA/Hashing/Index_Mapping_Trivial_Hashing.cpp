#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

bool has[MAX+1][2];




bool search(int X)
{
    if(X>=0)
    {
        if(has[X][0]==1)
            return true;
        else
        {
            return false;
        }
    }
    else
    {
        X=abs(X);
        if(has[X][1]==1)
            return true;
        else
        {
            return false;
        }
        
    }
    
}

void insert(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            has[arr[i]][0]=1;
        }
        else
        {
            has[abs(arr[i])][1]=1;
        }
    }
}



int main()
{
    int arr[]={-1,9,-5,-8,-5,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    insert(arr,n);
    int X = 4;
    if(search(X)==true)
          cout << "Present";  
    else
       cout << "Not Present"; 
}