// class Solution {
// public:
    
    
//     bool detectCycle_util(vector<vector<int>>& adj,vector<int>& visited,int v)
//     {
//         if(visited[v]==1)
//             return true;
//         if(visited[v]==2)
//             return false;
        
//         visited[v]=1;   //Mark current as visited
//         for(int i=0;i<adj[v].size();++i)
//             if(detectCycle_util(adj,visited,adj[v][i]))
//                 return true;
        
//         visited[v]=2;   //Mark current node as processed
//         return false;
//     }
    
//     //Cycle detection
//     bool detectCycle(vector<vector<int>>& adj,int n)
//     {
//         vector<int> visited(n,0);
//         for(int i=0;i<n;++i)
//             if(!visited[i])
//                 if(detectCycle_util(adj,visited,i))
//                     return true;
//         return false;
//     }
    
//     void dfs(vector<vector<int>>& adj,int v,vector<bool>& visited,stack<int>& mystack)
//     {
//         visited[v] = true;
//         for(int i=0;i<adj[v].size();++i)
//             if(!visited[adj[v][i]])
//                 dfs(adj,adj[v][i],visited,mystack);
        
//         mystack.push(v);
//     }
    
//     vector<int> findOrder(int numCourses, vector<vector<int>>& precs) {
     
//         int n = precs.size();
        
//         vector<vector<int>> adj(numCourses);
        
//         for(int i=0;i<n;i++){
//             adj[precs[i][1]].push_back(precs[i][0]);
//         }
        
//         vector<int> ans;
        
//         if(detectCycle(adj,numCourses)){
//             return ans;
//         }
        
//         stack<int> st;
//         vector<bool> visited(numCourses,false);
        
//         for(int i=0;i<numCourses;i++){
//             if(!visited[i])
//                 dfs(adj,i,visited,st);
//         }
        
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
        
//         return ans;
//     }
// };

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adjList[], int u, int v){
    adjList[u].push_back(v);
}


//using DFS
void findTopo(vector<int> adjList[], vector<int>& visited, stack<int>& st, int node){
    visited[node]=1;

    for(auto it : adjList[node]){
        if(!visited[it]){
            findTopo(adjList, visited, st, it);
        }
    }
    st.push(node);
}


//uisng BFS
vector<int> findTopoBFS(vector<int> adjList[], int V){
    queue<int> q;
    vector<int> ans;
    vector<int> indeg(V,0);

    for(int i=0;i<V;i++){
        for(auto it : adjList[i]){
            indeg[it]++;    
        }
    }

    for(int i=0;i<V;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }


    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);

        for(auto it : adjList[x]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }   
    }

    return ans;
}


int main(){
    int V = 6;
    vector<int> adjList[V];
    addEdge(adjList,4,0);
    addEdge(adjList,5,0);
    addEdge(adjList,5,2);
    addEdge(adjList,4,1);
    addEdge(adjList,2,3);
    addEdge(adjList,3,1);

    //dfs
    stack<int> st; 
    vector<int> visited(V,0);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            findTopo(adjList,visited,st,i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    cout<<endl;

    //bfs
    vector<int> ans;
    ans = findTopoBFS(adjList,V);

    for(int i=0;i<V;i++){
        cout<<ans[i]<<" ";
    }

}