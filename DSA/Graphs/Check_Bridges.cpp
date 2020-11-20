#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
    int V;
    list<int> *adjList;

    Graph(){}
    
    Graph(int V)
    {
        this->V=V;
        adjList=new list<int>[V];
    }

    void addEdge(int start, int end)
    {
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }


    void DFS(int v, bool visited[])
    {
        visited[v] = true; 
        
        list<int>::iterator i; 
        for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
            if(!visited[*i]) 
                DFS(*i, visited); 
    }


    bool isConnected()
    {
        bool visited[V];

        memset(visited,false,sizeof(visited));

        DFS(0,visited);

        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
                return false;
        }
        return true;
    }

    bool checkBridge(int u, int v)
    {
        adjList[u].remove(v);
        adjList[v].remove(u);

        bool res= isConnected();

        addEdge(u,v);

        return(res==false);
    }
};

int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 
  
    return 0; 
} 