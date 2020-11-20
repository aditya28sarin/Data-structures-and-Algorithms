#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
int vertex;

list<int> *adjList;

Graph()
{

}

Graph(int v)
{
    vertex=v;
    adjList=new list<int>[v];
}


void addEdge(int start, int end)
{
    adjList[start].push_back(end);
}

void DFSUtil(int node, bool visited[])
{
    visited[node]=true;
    list<int> :: iterator it;
    for(it=adjList[node].begin();it!=adjList[node].end();++it)
    {
        if(!visited[*it])
            DFSUtil(*it,visited);
    }
}

void DFSModified(int node, bool visited[], stack<int> &st)
{
     visited[node]=true;

    list<int> :: iterator it;
    for(it=adjList[node].begin();it!=adjList[node].end();++it)
    {
        if(!visited[*it])
            DFSModified(*it,visited,st);
    }
    st.push(node);
}

int findMother()
{
    bool visited[vertex];
    stack<int> st;
    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
            DFSModified(i,visited,st);
    }

    int v=st.top();

    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }

    DFSUtil(v,visited);

     for (int i=0; i<vertex; i++) 
        if (visited[i] == false) 
            return -1; 

    
    return v; 
}
};
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMother(); 
  
    return 0; 
}