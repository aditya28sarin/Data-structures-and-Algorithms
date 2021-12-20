#include<bits/stdc++.h> 
using namespace std; 

// class Graph 
// { 
        
// public: 

// 	int V; 
// 	list<int> *adj; 

// Graph(int V) 
// { 
// 	this->V = V; 
// 	adj = new list<int>[V]; 
// } 

// void addEdge(int v, int w) 
// { 
// 	adj[v].push_back(w);  
// } 


// bool detectCycleUtil(vector<bool> visited, int curr){
//     if(visited[curr]==true){
//         return true;
//     }

//     visited[curr]=true;
//     bool flag = false;
//     for(auto element: adj[curr]){
//         flag = detectCycleUtil(visited, element);

//         if(flag==true){
//             return true;
//         }
//     }
//     return false;
// }

// bool detectCycle(){

//     vector<bool> visited(V,false);
//     bool flag=false;

//     for(int i=0;i<V;i++){
//         visited[i]=true;
//         for(auto element: adj[i]){
//             flag = detectCycleUtil(visited, element);
//             if(flag==true){
//                 return true;
//             }
//         }
//         visited[i]=false;
//     }
//     return false;
// }

// };

// int main() 
// { 
// 	Graph g(6); 
//         g.addEdge(0, 1); 
//         g.addEdge(0, 3); 
//         g.addEdge(1, 2); 
//         // g.addEdge(0, 2); 
//         g.addEdge(3, 4); 
//         g.addEdge(4, 5); 
//         // g.addEdge(5, 3); 

// 	if(g.detectCycle()) 
//         cout << "Graph contains cycle"; 
//     else
//         cout << "Graph doesn't contain cycle"; 
//     return 0; 
// } 


void addEdge(vector<int> adjList[], int u, int v){
    adjList[u].push_back(v);
}

// DFS
bool isCycleUtil(vector<int> adjList[], int visited[], int dfsVisited[], int node){
    visited[node]=1;
    dfsVisited[node]=1;

    for(auto it : adjList[node]){
        if(!visited[it]){
            if(isCycleUtil(adjList, visited, dfsVisited, it)){
                return true;
            }
        }else if(dfsVisited[it]) return true;
    }

    dfsVisited[node]= 0;
    return false;
}

bool isCycle(vector<int> adjList[], int V){
    int visited[V+1], dfsVisited[V+1];
    memset(visited,0,sizeof(visited));
    memset(dfsVisited,0,sizeof(dfsVisited));


    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(isCycleUtil(adjList, visited, dfsVisited, i)){
                return true;
            }
        }   
    }
    return false;
}

bool isCycleUtil(vector<int> adjList[], vector<int>& visited, vector<int>& dfsVisited, int curr){
    visited[curr]=1;
    dfsVisited[curr]=1;

    for(auto it:adjList[curr]){
        if(!visited[it]){
            if(isCycleUtil(adjList,visited,dfsVisited,it)){
                return true;
            }
        }else if(dfsVisited[it]){
            return true;
        }
    }

    dfsVisited[curr]=0;
    return false;
}

bool isCycle(vector<int> adjList[], int V){
    vector<int> visited(V+1,0);
    vector<int> dfsVisited(V+1,0);

    for(int i=1;i<V;i++){
        if(!visited[i]){
            if(isCycleUtil(adjList,visited, dfsVisited, i)){
                return true;
            }
        }
    }

    return false;
}


// BFS
bool findTopoBFS(vector<int> adjList[], int V){
    queue<int> q;
    vector<int> indeg(V+1,0);

    for(int i=1;i<=V;i++){
        for(auto it : adjList[i]){
            indeg[it]++;    
        }
    }

    for(int i=1;i<=V;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cnt++;
        for(auto it : adjList[x]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }   
    }

    if(cnt==V){
        return false;
    }

    return true;

}



int main(){
    int V = 9;

    vector<int> adjList[V+1];
    addEdge(adjList,1,2);
    addEdge(adjList,2,3);
    addEdge(adjList,3,4);
    addEdge(adjList,4,5);
    addEdge(adjList,3,6);
    addEdge(adjList,6,5);
    addEdge(adjList,7,2);
    addEdge(adjList,7,8);
    addEdge(adjList,8,9);
    addEdge(adjList,9,7);

    if(isCycle(adjList,V)){
        cout<<"Cycle is present in the directed graph."<<endl;
    }else{
        cout<<"Cycle is not present in the directed graph."<<endl;
    }


    if(findTopoBFS(adjList,V)){
        cout<<"Cycle is present in the directed graph."<<endl;
    }else{
        cout<<"Cycle is not present in the directed graph."<<endl;
    }
}