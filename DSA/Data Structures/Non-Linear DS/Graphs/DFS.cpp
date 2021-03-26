#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int,list<int>> adjList;
    map<int,bool> visited;

    void addEdge(int x, int y){
        adjList[x].push_back(y);
    }

    void DFS(int start){
        
        visited[start]=true;
        cout<<start<<" ";

        list<int> :: iterator it;

        for(it=adjList[start].begin();it!=adjList[start].end();++it){
            if(!visited[*it]){
                visited[*it]=true;
                DFS(*it);
            }
        }
    }
};

int main(){
    
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
}