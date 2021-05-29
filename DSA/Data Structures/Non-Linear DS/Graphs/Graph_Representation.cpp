#include<bits/stdc++.h>
using namespace std;


//adjacency matrix
int N,M;
void createAdjMatrix(int Adj[][6], int arr[][2]){
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            Adj[i][j]=0;
        }
    }

    for(int i=0;i<M;i++){
        int x = arr[i][0];
        int y = arr[i][1];

        Adj[x][y]=1;
        Adj[y][x]=1;
    }

}

void printAdjMatrix(int Adj[][6]) 
{ 
    for (int i = 1; i < N + 1; i++) { 
        for (int j = 1; j < N + 1; j++) { 
     
          printf("%d ", Adj[i][j]); 
        } 
        printf("\n"); 
    } 
}


//adjancency list  --> using STL List 
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V){

    for(int i=0;i<V;i++){
        cout << "\n Adjacency list of vertex "
             << i << "\n head ";

        for(auto x:adj[i]){
            cout<<"->"<<x;
        }
        printf("\n");
    }
}



//adjacency list --> map 
class Graph{
    unordered_map<int,list<int>> adjList;
    public:
        Graph(){

        }

        void addEdge(int u, int v, int bidir=true){
            adjList[u].push_back(v);
            if(bidir){
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto row:adjList){
                int key = row.first;
                cout<<key<<"->";

                for(auto element:row.second){
                    cout<<element<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){

    //adjacency matrix 
    N = 5;
    int arr[][2]={{1,2}, {2,3}, {4,5}, {1,5}};
    M = sizeof(arr)/sizeof(arr[0]);
    int Adj[6][6];
    createAdjMatrix(Adj,arr);
    printAdjMatrix(Adj); 


    //adjancency List 
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);

    //adj list -> map
    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,2);

    g.printAdjList();

}
