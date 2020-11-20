
//Strongly directed components --> Kosaraju Algorithm
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
    cout<<node<<" ";
    
    list<int> :: iterator it;
    for(it=adjList[node].begin();it!=adjList[node].end();++it)
    {
        if(!visited[*it])
            DFSUtil(*it,visited);
    }
}


Graph getTranspose()
{

    Graph g(vertex);
    for(int i=0;i<vertex;i++)
    {
        list<int> :: iterator it;

        for(it=adjList[i].begin();it!=adjList[i].end();++it)
        {
            g.adjList[*it].push_back(i);
        }

    }
    return g;
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


bool checkSSC()
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
    Graph gr=getTranspose();

    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }

    while(!st.empty())
    {
        int v = st.top();
        st.pop();

        if(visited[v]==false)
        {
             gr.DFSUtil(v,visited);
             cout<<endl;
        }
    }
}

};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.checkSSC(); 
  
    return 0; 
} 