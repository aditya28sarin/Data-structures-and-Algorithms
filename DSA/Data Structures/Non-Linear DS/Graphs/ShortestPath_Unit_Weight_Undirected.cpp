#include<bits/stdc++.h>
using namespace std;

// class Graph{
// public:
// 	int vertex;

// 	list<int> *adjList;

// 	Graph(int v)
// 	{
// 		vertex=v;
// 		adjList=new list<int>[v]; 
// 	}

// 	void addVertex(int u, int v, bool bidr=true)
// 	{
// 		adjList[u].push_back(v);
		
// 		if(bidr)
// 		{
// 			adjList[v].push_back(u);
// 		}
// 	}	
 
// 	void printAdjList()
// 	{
// 		for(int i=0;i<vertex;i++)
// 		{
// 			cout<<i<<"->";
// 			for(int node:adjList[i])
// 			{
// 				cout<<node<<",";
// 			}
// 			cout<<endl;
// 		}
// 	}

//     void BFS(int start, int end)
//     {
//         queue<int> q;

//         bool *visited = new bool[vertex+1]{0};
//         int *parent = new int[vertex+1]{-1};
//         int *distance = new int[vertex+1]{0};

//         q.push(start);
//         visited[start]=true;

//         while(!q.empty()){
//             int temp = q.front();
//             q.pop();

//             for(auto neighbor : adjList[temp]){
//                 if(!visited[neighbor]){
//                     q.push(neighbor);
//                     visited[neighbor]=true;
//                     parent[neighbor]=temp;
//                     distance[neighbor]=distance[temp]+1;
//                 }
//             }
//         } 
        
//         cout<<"Shortest path from "<<start<<"to "<<end<<" is:"<<distance[end]<<endl;

//         int val = end;
//         while(val!=-1){
//             cout<<val<<"->";
//             val=parent[val];
//         }
//     }
// };


// int main()
// {
// 	Graph g(6);

// 	g.addVertex(0,1);
// 	g.addVertex(1,2);
// 	g.addVertex(0,4);
// 	g.addVertex(2,4);
// 	g.addVertex(3,2);
// 	g.addVertex(2,3);
// 	g.addVertex(3,5);
//     g.addVertex(3,4);
    

// 	//g.printAdjList();	
// 	g.BFS(0,5);
// }


// void addEdge(vector<int> adjList[], int u, int v){
// 	adjList[u].push_back(v);
// 	adjList[v].push_back(u);
// }

// void shortestPath(vector<int> adjList[], int V, int src){
// 	vector<int> dist(V+1,INT_MAX);
// 	queue<int> q;

// 	q.push(src);
// 	dist[src]=0;
// 	while(!q.empty()){
// 		int x = q.front();
// 		q.pop();

// 		for(auto it : adjList[x]){
// 			if(dist[x]+1<dist[it]){
// 				dist[it]=dist[x]+1;
// 				q.push(it);
// 			}
// 		}
// 	}

// 	for(int i=0;i<V;i++) cout<<dist[i]<<" ";
// }



void addEdge(vector<int> adjList[], int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}


void shortestPath(vector<int> adjList[], int V, int src){
	vector<int> dist(V+1,INT_MAX);
	queue<int> q;

	q.push(src);
	dist[src]=0;

	while(!q.empty()){
		int n=q.front();
		q.pop();

		for(auto it:adjList[n]){
			if(dist[it]>dist[n]+1){
				dist[it]=dist[n]+1;
				q.push(it);
			}
		}
	}

	for(int i=0;i<V;i++){
		cout<<dist[i]<<" ";
	}
}

int main(){
	int V = 9;
	vector<int> adjList[V+1];
	addEdge(adjList,0,1);
	addEdge(adjList,0,3);
	addEdge(adjList,1,2);
	addEdge(adjList,3,4);
	addEdge(adjList,4,5);
	addEdge(adjList,5,6);
	addEdge(adjList,2,6);
	addEdge(adjList,6,7);
	addEdge(adjList,7,8);
	addEdge(adjList,6,8);

	shortestPath(adjList,V,0);
}