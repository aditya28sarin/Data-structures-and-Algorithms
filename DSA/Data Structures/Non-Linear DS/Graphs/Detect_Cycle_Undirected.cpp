#include<bits/stdc++.h> 
#include<set>
using namespace std; 

class Graph 
{ 
        
public: 

	int V; 
	list<int> *adj; 

Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void addEdge(int v, int w) 
{ 
	adj[v].push_back(w);  
	adj[w].push_back(v);  
} 


bool detectCycle()
{
  
  set<int>  visited;
    
    for(int i=0;i<V;i++)
    {
        if(visited.find(i)==visited.end())
        {
            if(DFS(i,-1,visited,g,V))
            {
                return true;
            }
        }
    }
    return false;
   
}

void moveVertex(int current,set<int> &visited)
{
    visited.insert(current);
}

bool DFS(int current, int parent, set<int> &visited)
{
    moveVertex(current, visited);

    for(int neighbor: adj[current])
    {
        if(neighbor!=parent)
        {
            if(visited.find(neighbor)!=visited.end())
                return true;
    
            if(DFS(neighbor,current,visited))
            {
                return true;
            }
        }
    }
     return false;
}


};

int main() 
{ 
	Graph g(6); 
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(2, 3); 
        g.addEdge(0, 2); 
        g.addEdge(3, 4); 
        g.addEdge(4, 5); 
        g.addEdge(2, 5); 

	if(g.detectCycle()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
} 



// using disjoint set (Union Find)

#include<bits/stdc++.h>
using namespace std;
int find(int val, vector<int> parent);
void Union(int first, int second,vector<int> &parent)
{
    first=find(first,parent);
    second=find(second,parent);
    parent[first]=second;
}

int find(int val, vector<int> parent)
{
    if(parent[val]==-1)
        return val;
    
    return find(parent[val],parent);
}

bool isCyclic(vector<pair<int,int>> &edge_List, vector<int> &parent)
{
    for(auto edge:edge_List)
    {
        int firstVal=find(edge.first,parent);
        int secondVal=find(edge.second,parent);

        if(firstVal==secondVal)
            return true;

        Union(firstVal,secondVal,parent);
    }
    return false; 
}

int main()
{
    int nodes,edges;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>nodes;
    cout<<"Enter the number of edges: "<<endl;
    cin>>edges;

    vector<pair<int,int>> edgeList;

    vector<int> parent(nodes);

    for(int i=0;i<nodes;i++)
    {
        parent[i]=-1;
    }

    int first, second;
    for(int i=0;i<edges;i++)
    {
        cin>>first>>second;
        edgeList.push_back({first,second});
    }

    if(isCyclic(edgeList,parent))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";
	
	return 0;
}




// with path compression and Rank

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int parent;
    int rank;
};

int find(int val, vector<Node> dsuf);

void Union(int first, int second,vector<Node> &dsuf)
{
    if(dsuf[first].rank>dsuf[second].rank)
        dsuf[second].parent=first;
    
    else if(dsuf[first].rank<dsuf[second].rank)
        dsuf[first].parent=second;

    else
    {
        dsuf[first].parent=second;
        dsuf[second].rank+=1;
    }
    
}

int find(int val, vector<Node> dsuf)
{
    if(dsuf[val].parent==-1)
        return val;
    
    return dsuf[val].parent=find(dsuf[val].parent,dsuf);
}

bool isCyclic(vector<pair<int,int>> &edge_List, vector<Node> &dsuf)
{
    for(auto edge:edge_List)
    {
        int firstVal=find(edge.first,dsuf);
        int secondVal=find(edge.second,dsuf);

        if(firstVal==secondVal)
            return true;

        Union(firstVal,secondVal,dsuf);
    }
    return false; 
}

int main()
{
    int nodes,edges;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>nodes;
    cout<<"Enter the number of edges: "<<endl;
    cin>>edges;

    vector<pair<int,int>> edgeList;

    vector<Node> dsuf(nodes);

    for(int i=0;i<nodes;i++)
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    int first, second;
    for(int i=0;i<edges;i++)
    {
        cin>>first>>second;
        edgeList.push_back({first,second});
    }

    if(isCyclic(edgeList,dsuf))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";
	
	return 0;
}