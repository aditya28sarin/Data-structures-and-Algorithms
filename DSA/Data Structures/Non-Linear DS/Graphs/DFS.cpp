#include<bits/stdc++.h>
using namespace std;

// class Graph{
// public:
//     map<int,list<int>> adjList;
//     map<int,bool> visited;

//     void addEdge(int x, int y){
//         adjList[x].push_back(y);
//     }

//     void DFS(int start){
        
//         visited[start]=true;
//         cout<<start<<" ";

//         list<int> :: iterator it;

//         for(it=adjList[start].begin();it!=adjList[start].end();++it){
//             if(!visited[*it]){
//                 visited[*it]=true;
//                 DFS(*it);
//             }
//         }
//     }
// };

// int main(){
    
//     Graph g;
//     g.addEdge(0,1);
//     g.addEdge(0, 9);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(9, 3);
 
//     cout << "Following is Depth First Traversal"
//             " (starting from vertex 2) \n";
//     g.DFS(2);
// }


void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsans(vector<int> adjList[], vector<int>& visited, vector<int>& ans, int node){
    ans.push_back(node);
    visited[node]=1;
    for(auto it : adjList[node]){
        if(!visited[it]){
            dfsans(adjList,visited,ans,it);
        }
    }

}


int main(){
    int V = 7;
    vector<int> adjList[V+1];
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 5);
    addEdge(adjList, 4, 6);
    addEdge(adjList, 5, 7);
    addEdge(adjList, 7, 2);
    
    vector<int> visited(V+1,0);
    vector<int> dfsans;

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            dfsans(adjList, visited, dfsans, i);
        }
    }
}