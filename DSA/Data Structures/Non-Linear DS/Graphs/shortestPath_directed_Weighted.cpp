#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<pair<int,int>> adjList[], int u, int v, int wt){
    adjList[u].push_back({v,wt});
}

void findTopoSort(vector<pair<int,int>> adjList[], int visited[], stack<int>& st, int node){
    visited[node]=1;

    for(auto it : adjList[node]){
        if(!visited[it.first]){
            findTopoSort(adjList, visited, st, it.first);
        }
    }
    st.push(node);
}

void shortestPath(vector<pair<int,int>> adjList[], int V, int src){
    int visited[V]={0};
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            findTopoSort(adjList,visited,st,i);
        }
    }

    int distance[V];
    for(int i=0;i<V;i++){
        distance[i]=INT_MAX;
    }

    distance[src]=0;

    while(!st.empty()){
        int x = st.top();
        st.pop();

       if(distance[x]!=INT_MAX){
            for(auto it : adjList[x]){
            if(distance[x] + it.second  < distance[it.first]){
                distance[it.first] = distance[x] + it.second;
            }
        }
       }
    }

    for(int i=0;i<V;i++){
        if(distance[i] == INT_MAX){
            cout<<"INF "; 
        }else{
            cout<<distance[i]<<" ";
        }
    }
}

int main(){
    int V = 6;
    vector<pair<int,int>> adjList[V];

    addEdge(adjList,0,1,2);
    addEdge(adjList,0,4,1);
    addEdge(adjList,1,2,3);
    addEdge(adjList,4,2,2);
    addEdge(adjList,2,3,6);
    addEdge(adjList,4,5,4);
    addEdge(adjList,5,3,1);


    shortestPath(adjList, V, 0);
}