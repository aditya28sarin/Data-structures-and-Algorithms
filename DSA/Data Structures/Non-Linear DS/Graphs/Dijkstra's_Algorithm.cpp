#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adjList[], int u, int v, int wt){
    adjList[u].push_back({v,wt});
    adjList[v].push_back({u,wt});
}

void dijkstraAlgo(vector<pair<int,int>> adjList[], int V, int src){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> distance(V+1,INT_MAX);
    distance[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;

        pq.pop();

        for(auto itr : adjList[prev]){
            int next=itr.first;
            int nextDist=itr.second;

            if(distance[next]>distance[prev]+nextDist){
                distance[next]=distance[prev]+nextDist;
                pq.push({distance[next],next});
            }
        }
    } 


    cout<<"Distance from source "<<src<<" are:";

    for(int i=1;i<=V;i++){
        cout<<distance[i]<<" ";
    }
}

void dijkstraAlgo(vector<pair<int,int>> adjList[], int V, int src){
    vector<int> distance (V,INT_MAX);

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

}

int main(){
    int V = 5;
    vector<pair<int,int>> adjList[V+1];
    addEdge(adjList,1,2,2);
    addEdge(adjList,2,5,5);
    addEdge(adjList,5,3,1);
    addEdge(adjList,3,2,4);
    addEdge(adjList,3,4,3);
    addEdge(adjList,4,1,1);

    dijkstraAlgo(adjList,V,1);
}