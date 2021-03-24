#include<bits/stdc++.h>
using namespace std;

// #include<bits/stdc++.h>
// using namespace std;

// // Adjacency Matrix Representation 
// int N,M;
// void createAdjMatrix(int Adj[][6], int arr[][2])
// {
//     for(int i=0;i<N+1;i++)
//     {
//         for(int j=0;j<N+1;j++)
//         {
//             Adj[i][j]=0;
//         }
//     }

//     for(int i=0;i<M;i++)
//     {
//         int x = arr[i][0];
//         int y = arr[i][1];

//         Adj[x][y]=1;
//         Adj[y][x]=1;
//     }
// }

// void printAdjMatrix(int Adj[][6]) 
// { 
//     for (int i = 1; i < N + 1; i++) { 
//         for (int j = 1; j < N + 1; j++) { 
     
//           printf("%d ", Adj[i][j]); 
//         } 
//         printf("\n"); 
//     } 
// } 

// int main()
// {
//     N = 5;

//     int arr[][2] = { { 1, 2 }, { 2, 3 },  
//             { 4, 5 }, { 1, 5 } };

//     M = sizeof(arr)/sizeof(arr[0]);

//     int Adj[6][6];

//     createAdjMatrix(Adj,arr);

//      printAdjMatrix(Adj); 
  
//     return 0; 
// }


// //Adjacency List --> using List STL 
// class Graph
// {
//     int vertex;
    
//     list<int> *adjList; 

//     Graph()
//     {

//     }

//     Graph(int v)
//     {
//         vertex=v;

//         adjList=new list<int>[v];
//     }

//     void addEdge(int u, int v, int bidir=true)
//     {
//         adjList[u].push_back(v);

//         if(bidir)
//         {
//             adjList[v].push_back(u);
//         }
//     }


//     void printList()
//     {
//         for(int i=0;i<vertex;i++)
//         {
//             cout<<i<<"->";

//             for(auto element : adjList[i])
//             {
//                 cout<<element<<",";
//             }
//             cout<<endl;
//         }
//     }
// };


// int main()
// {
// 	Graph g(4);

// 	g.addVertex(0,1);
// 	g.addVertex(0,2);
// 	g.addVertex(0,3);
// 	g.addVertex(1,3);
// 	g.addVertex(3,2);

// 	g.printAdjList();	
	
// }




// //Adjacency List --> using List STL in a Map  
// template <typename T>
// class Graph{

// map<T,list<T>> adjList;

// public:

//     Graph()
//     {

//     }   

//     void addEdge(T u, T v, bool bidir=true)
//     {
//         adjList[u].push_back(v);

//         if(bidir)
//         {
//             adjList[v].push_back(u);
//         }
//     } 

//     void printAdjList()
//     {
//         for(auto row:adjList)
//         {
//             T key = row.first;
//             cout<<key<<"->";

//             for(auto element: row.second)
//             {
//                 cout<<element<<",";
//             }

//             cout<<endl;
//         }
//     }
// };


// int main()
// {
//     Graph<string> g;
//     g.addEdge("Amritsar","Delhi");
//     g.addEdge("Amritsar", "jaipur");
//     g.addEdge("Delhi", "Siachen");
//     g.addEdge("Delhi", "Bangalore");
//     g.addEdge("Delhi", "Agra");
//     g.addEdge("Amritsar", "Siachen");


//     g.printAdjList();
// }



// //Adjacency List --> using vector STL
// #include<bits/stdc++.h> 
// using namespace std; 


// void addEdge(vector<int> adj[], int u, int v) 
// { 
// 	adj[u].push_back(v); 
// 	adj[v].push_back(u); 
// } 

// void DFSUtil(int u, vector<int> adj[], 
// 					vector<bool> &visited) 
// { 
// 	visited[u] = true; 
// 	cout << u << " "; 
// 	for (int i=0; i<adj[u].size(); i++) 
// 		if (visited[adj[u][i]] == false) 
// 			DFSUtil(adj[u][i], adj, visited); 
// } 
 
// void DFS(vector<int> adj[], int V) 
// { 
// 	vector<bool> visited(V, false); 
// 	for (int u=0; u<V; u++) 
// 		if (visited[u] == false) 
// 			DFSUtil(u, adj, visited); 
// } 

// // Driver code 
// int main() 
// { 
// 	int V = 5; 

// 	vector<int> adj[V]; 

// 	addEdge(adj, 0, 1); 
// 	addEdge(adj, 0, 4); 
// 	addEdge(adj, 1, 2); 
// 	addEdge(adj, 1, 3); 
// 	addEdge(adj, 1, 4); 
// 	addEdge(adj, 2, 3); 
// 	addEdge(adj, 3, 4); 
// 	DFS(adj, V); 
// 	return 0; 
// } 



// //Adjacency List --> using unordered_set 
// //similar to first method
// class Graph{
//     int vertex;

//     unordered_set<int> * adjList;
// };


// Graph* createGraph(int v)
// {
//     Graph* g =new Graph;
//     Graph->vertex=v;

//     Graph->adjList = new unordered_set<int>[v];

//     return g;  
// }

// void addEdge(Graph* g, int src, int des)
// {
//     g->adjList[src].insert(des);

//     g->adjList[des].insert(src);
// }


// void printGraph(Graph* g)
// {
//     for(int i =0;i<g->vertex;++i)
//     {
//         unordered_set lst= g->adjList;

//         cout<<i<<"->";

//         for(auto i=lst.begin(); i!=lst.end(); ++i)
//         {
//             cout<<*i<<",";
//         }
//         cout<<endl;
//     }
// }


// void searchEdge(Graph* graph, int src, int dest)
// {
//     auto itr = graph->adjList[src].find(dest); 
//     if (itr == graph->adjList[src].end()) 
//         cout << endl << "Edge from " << src 
//              << " to " << dest << " not found."
//              << endl; 
//     else
//         cout << endl << "Edge from " << src 
//              << " to " << dest << " found."
//              << endl; 
// }


// int main()
// {
//      int V = 5; 
//     struct Graph* graph = createGraph(V); 
//     addEdge(graph, 0, 1); 
//     addEdge(graph, 0, 4); 
//     addEdge(graph, 1, 2); 
//     addEdge(graph, 1, 3); 
//     addEdge(graph, 1, 4); 
//     addEdge(graph, 2, 3); 
//     addEdge(graph, 3, 4); 
  
  
//     printGraph(graph); 
  
//     searchEdge(graph, 2, 1); 
//     searchEdge(graph, 0, 3); 
  
//     return 0; 
// }



// //weighted graph 

// void addEdge(vector<pair<int,int>> adjList[], int start, int end, int wt)
// {
//     adjList[start].push_back(make_pair(end, wt));
//     adjList[end].push_back(make_pair(start, wt));
// }

// void printList((vector<pair<int,int>> adjList[], int V)
// {

//     for(int i=0;i<V;i++)
//     {
//         cout<<i<<"->";

//         for(auto it = adjList.begin(); it!=adjList.end(); it++)
//         {
//             cout<<"Node "<< it->first<<" with an edge "<<it->second<<endl;
//         }

//         cout<<endl;
//     }
// }


// int main()

// {
//      int V = 5; 

//     vector<pair<int, int> > adj[V]; 

//     addEdge(adj, 0, 1, 10); 

//     addEdge(adj, 0, 4, 20); 

//     addEdge(adj, 1, 2, 30); 

//     addEdge(adj, 1, 3, 40); 

//     addEdge(adj, 1, 4, 50); 

//     addEdge(adj, 2, 3, 60); 

//     addEdge(adj, 3, 4, 70); 

//     printGraph(adj, V); 

//     return 0; 
// }