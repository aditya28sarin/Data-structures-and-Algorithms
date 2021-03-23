#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
    int V;
    list<pair<int,int>> *adjList;

    Graph() 
    {
        
    }  

    Graph(int V)
    {
        this->V=V;
        adjList=new list<pair<int,int>>[V];
    } 

    void addEdge(int start, int end, int weight)
    {
        adjList[start].push_back(make_pair(end,weight));
        adjList[end].push_back(make_pair(start,weight));
    }


void printPath(int parent[], int j)
{
    if(parent[j]==-1)
        return;

    printPath(parent,parent[j]);

    cout<<j<<" ";
}

int printSolution(vector<int> &dist, int parent[], int n)
{
    int src=0;
    printf("Vertex\t Distance\tPath"); 
    for (int i = 1; i < V; i++) 
    { 
        printf("\n%d -> %d \t\t %d\t\t%d ", 
                        src, i, dist[i], src); 
        printPath(parent, i); 
    } 
}

    void shortestPath(int src)
    {
        set<pair<int,int>> st;
        int parent[V];

        for(int i=0;i<V;i++)
        {
            parent[i]=-1;
        }
        vector<int> dist(V,5000);

        st.insert(make_pair(0,src));
        dist[src]=0;


        while(!st.empty())
        {
            pair<int,int> tmp=*(st.begin());
            st.erase(st.begin());

            int u=tmp.second;
            list<pair<int,int>> :: iterator it;

            for(it=adjList[u].begin();it!=adjList[u].end();++it)
            {
                int v=(*it).first;
                int wt=(*it).second;

                if(dist[v]>dist[u]+wt)
                {

                    if(dist[v]!=5000)
                    {
                        st.erase(st.find(make_pair(dist[v],v)));
                    }
                    dist[v]=dist[u]+wt;
                    st.insert(make_pair(dist[v],v));
                    parent[v]=u;
                }
            }
        }
         printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 

    cout<<endl;
    cout<<printSolution(dist, parent, V); 

    }
};


int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
  
    return 0; 
}
