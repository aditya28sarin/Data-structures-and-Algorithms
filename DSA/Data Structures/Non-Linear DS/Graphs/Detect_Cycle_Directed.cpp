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
} 


bool detectCycle()
{
    set<int> not_visited;
    set<int>  visiting;
    set<int>  visited;

    for(int i=0;i<V;i++)
    {
        not_visited.insert(i);
    }    

    while(not_visited.size()>0)
    {
        int current = random(not_visited);
        if(DFS(current, not_visited,visiting,visited))
        {
            return true;
        }
    }
    return false;
}

int random(set<int> &st)
{
    set<int> :: iterator it = st.begin();
    int random = rand() % st.size();
    advance(it,random);

    return *it;
}

void moveVertex(int current,set<int> &not_visited,set<int> &visiting)
{
    not_visited.erase(current);
    visiting.insert(current);
}

bool DFS(int current,set<int> &not_visited, set<int> &visiting, set<int> &visited)
{
    moveVertex(current, not_visited, visiting);

    for(int neighbor: adj[current])
    {
 
        
        if(visited.find(neighbor)!=visited.end())
            continue;

        if(visiting.find(neighbor)!=visiting.end())
            return true;

        if(DFS(neighbor,not_visited,visiting,visited))
        {
            return true;
        }
       
    }

    moveVertex(current, visiting, visited);
     return false;
}


};

int main() 
{ 
	Graph g(6); 
        g.addEdge(0, 1); 
        g.addEdge(0, 3); 
        g.addEdge(1, 2); 
        g.addEdge(0, 2); 
        g.addEdge(3, 4); 
        g.addEdge(4, 5); 
        g.addEdge(5, 3); 

	if(g.detectCycle()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
} 