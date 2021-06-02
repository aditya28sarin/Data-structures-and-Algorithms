// #include<bits/stdc++.h>
// using namespace std;

// class DisSet{
// public:
//     int *rank;
//     int *parent;
//     int n;

//     DisSet(int n)
//     {
//         rank=new int[n];
//         parent=new int[n];
//         this->n=n;
//     }

//     void makeSet()
//     {
//         for(int i=0;i<n;i++)
//         {
//             parent[i]=i;
//         }
//     }

//     int find(int x)
//     {
//         if(parent[x]!=x)
//         {
//             parent[x]=find(parent[x]);
//         }

//         return parent[x];
//     }

//     void Union(int x, int y)
//     {
//         int xSet=find(x);
//         int ySet=find(y);

//         if(xSet==ySet)
//             return;

//         if(rank[xSet]>rank[ySet])
//         {
//             parent[ySet]=xSet;
//         }
//         else if (rank[ySet]>rank[xSet])
//         {
//             parent[xSet]=ySet;
//         }
//         else
//         {
//             parent[ySet]=xSet;
//             rank[xSet]=rank[xSet]+1;
//         }
        
//     }
// };



// int main()
// {
//     DisSet obj(5);
//     obj.Union(0, 2); 
//     obj.Union(4, 2); 
//     obj.Union(3, 1); 
//     if (obj.find(4) == obj.find(0)) 
//         cout << "Yes\n"; 
//     else
//         cout << "No\n"; 
//     if (obj.find(1) == obj.find(0)) 
//         cout << "Yes\n"; 
//     else
//         cout << "No\n"; 
  
//     return 0; 
// }


#include<bits/stdc++.h>
using namespace std;

int parentArr[100000];
int rankArr[100000];
int n = 7;

void makeSet(){
    for(int i=1;i<=n;i++){
        parentArr[i]=i;
        rankArr[i]=0;
    }
}

int findParent(int x){
    if(x==parentArr[x])
        return x;
    
    return parentArr[x] = findParent(parentArr[x]);
}

void unionDS(int x, int y){
    int u = findParent(x);
    int v = findParent(y);


    if(rankArr[u] < rankArr[v]){
        parentArr[u] = v;
    }else if (rankArr[u] > rankArr[v]){
        parentArr[v] = u;
    }else{
        parentArr[v] = u;
        rankArr[u]++;
    }
}

int main(){
    makeSet();
    int m;

    cin>>m;
    while(m--){
        int u, v;
        unionDS(u,v);
    }

    if(findParent(2)!=findParent(3)){
        cout<<"Different Component"<<endl;
    }else{
        cout<<"Same Component"<<endl;
    }
}