#include<bits/stdc++.h>
using namespace std;

class DisSet{
public:
    int *rank;
    int *parent;
    int n;

    DisSet(int n)
    {
        rank=new int[n];
        parent=new int[n];
        this->n=n;
    }

    void makeSet()
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y)
    {
        int xSet=find(x);
        int ySet=find(y);

        if(xSet==ySet)
            return;

        if(rank[xSet]>rank[ySet])
        {
            parent[ySet]=xSet;
        }
        else if (rank[ySet]>rank[xSet])
        {
            parent[xSet]=ySet;
        }
        else
        {
            parent[ySet]=xSet;
            rank[xSet]=rank[xSet]+1;
        }
        
    }
};



int main()
{
    DisSet obj(5);
    obj.Union(0, 2); 
    obj.Union(4, 2); 
    obj.Union(3, 1); 
    if (obj.find(4) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
  
    return 0; 
}