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


bool detectCycleUtil(vector<bool> visited, int curr){
    if(visited[curr]==true){
        return true;
    }

    visited[curr]=true;
    bool flag = false;
    for(auto element: adj[curr]){
        flag = detectCycleUtil(visited, element);

        if(flag==true){
            return true;
        }
    }
    return false;
}

bool detectCycle(){

    vector<bool> visited(V,false);
    bool flag=false;

    for(int i=0;i<V;i++){
        visited[i]=true;
        for(auto element: adj[i]){
            flag = detectCycleUtil(visited, element);
            if(flag==true){
                return true;
            }
        }
        visited[i]=false;
    }
    return false;
}

};

int main() 
{ 
	Graph g(6); 
        g.addEdge(0, 1); 
        g.addEdge(0, 3); 
        g.addEdge(1, 2); 
        // g.addEdge(0, 2); 
        g.addEdge(3, 4); 
        g.addEdge(4, 5); 
        // g.addEdge(5, 3); 

	if(g.detectCycle()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
} 