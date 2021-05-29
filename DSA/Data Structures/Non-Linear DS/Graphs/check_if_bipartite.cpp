// URL: https://leetcode.com/problems/possible-bipartition/

// class Solution {
// public:
    
    
//     bool isBi(vector<vector<int>>& dislikes, vector<int>& color, int parent, int N){
//         queue<int> q;
//         q.push(parent);
//         color[parent]=1;
        
//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();
//             for(auto element: dislikes[curr]){
//                 if(color[element]==color[curr]){
//                     return false;
//                 }if(color[element]==-1){
//                     color[element]=1-color[curr];
//                     q.push(element);
//                 }
//             }
//         }
//         return true;
//     }
    
//     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
     
//         vector<int> color(N+1,-1);
//          int n = dislikes.size();
//         vector<vector<int>>adj(N+1);
    
//         for(int i=0;i<n;i++){
//             adj[dislikes[i][0]].push_back(dislikes[i][1]);
//             adj[dislikes[i][1]].push_back(dislikes[i][0]);
//         }
        
//         for(int i=1;i<=N;i++){
//             if(color[i]==-1){
//                 if(!isBi(adj,color,i,N)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };



#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

bool isBipartiteUtil(vector<int> adjList[], int node, int color[]){
    queue<int> q;
    color[node]=1;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it : adjList[x]){
            if(color[it]==-1){
                color[it]=1-color[x];
                q.push(it);
            }else if(color[it]==color[x]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<int> adjList[], int V){
    int color[V];
    memset(color, -1, sizeof(color));
    for(int i=1;i<=V;i++){
        if(color[i]==-1){
            if(!isBipartiteUtil(adjList, i, color)){
                return false;
            }
        }
    }
    return true;
}


//with dfs

bool isBipartiteDFSUtil(vector<int> adjList[], int node, int color[]){
    
    if(color[node]==-1) color[node]=1;

    for(auto it : adjList[node]){
        if(color[it]==-1){
            color[it] = 1- color[node];
            if(!isBipartiteDFSUtil(adjList,it,color)){
                return false;
            }
        }
        else if(color[it]==color[node]){
                return false;
        }
    }
    return true;
}

bool isBipartiteDFS(vector<int> adjList[], int V){
    int color[V];
    memset(color, -1, sizeof(color));
    for(int i=1;i<=V;i++){
        if(color[i]==-1){
            if(!isBipartiteDFSUtil(adjList, i, color)){
                return false;
            }
        }
    }
    return true;
}


int main(){
    int V = 11;
    vector<int> adjList[V+1];
    addEdge(adjList,1,2);
    addEdge(adjList,2,4);
    addEdge(adjList,3,5);
    addEdge(adjList,5,6);
    addEdge(adjList,6,7);
    addEdge(adjList,7,8);
    addEdge(adjList,8,11);
    addEdge(adjList,8,9);
    addEdge(adjList,9,5);


    if(isBipartite(adjList,V)){
        cout<<"Graph is Bipartite"<<endl;
    }else{
        cout<<"Graph is not Bipartite"<<endl;
    }

    if(isBipartiteDFS(adjList, V)){
        cout<<"Graph is Bipartite"<<endl;
    }else{
        cout<<"Graph is not Bipartite"<<endl;
    }
}