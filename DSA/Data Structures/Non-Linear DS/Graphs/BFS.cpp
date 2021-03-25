#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int V){
            this->V=V;
            adj = new list<int>[V];
        }

        void addEdge(int x, int y){
            adj[x].push_back(y);
        }
        void BFS(int source){


            bool *visited = new bool[V];
            for(int i=0;i<V;i++){
                visited[i]=false;
            }
            
            visited[source]=true;
            queue<int> q;
            q.push(source);

            list<int> :: iterator it;

            while(!q.empty()){
                int x = q.front();
                cout<<x<<" ";
                q.pop();

                for(it=adj[x].begin();it!=adj[x].end();++it){

                    if(!visited[*it]){
                        visited[*it]=true;
                        q.push(*it);
                    }
                }
            }
        }
};




//map style 
class Graph1 {
public:
    int vertex;
    unordered_map<int,list<int>> adjList;

    void addEdge(int x, int y, int bidir=true){
        adjList[x].push_back(y);

        if(bidir){
            adjList[y].push_back(x);
        }
    }

    void BFS1(int start){

        queue<int> q;
        bool *visited = new bool[adjList.size()+1]{0};
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int x = q.front();
            cout<<x<<" ";
            q.pop();

            for(auto element:adjList[x]){
                if(!visited[element]){
                    visited[element]=true;
                    q.push(element);
                }
            }
        }
    }

};



int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);


    cout<<endl;

    Graph1 g1;

    g1.addEdge(0,1);
	g1.addEdge(1,2);
	g1.addEdge(0,4);
	g1.addEdge(2,4);
	g1.addEdge(3,2);
	g1.addEdge(2,3);
	g1.addEdge(3,5);

    g1.BFS1(0);
}
