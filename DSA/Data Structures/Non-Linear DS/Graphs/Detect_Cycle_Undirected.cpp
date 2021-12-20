// URL: https://www.youtube.com/watch?v=eTaWFhPXPz4&t=1369s


//Using Disjoint Set (Not optimized)
#include<bits/stdc++.h>
using namespace std;

// int find(vector<int>& dsuf,int element){

//         if(dsuf[element]==-1){
//             return element;
//         }else{
//             return find(dsuf,dsuf[element]);
//         }
// }

// void unionDS(vector<int>& dsuf, int fromP, int toP){
//     fromP=find(dsuf,fromP);
//     toP=find(dsuf,toP);
//     dsuf[fromP]=toP;
// }

// bool detectCycle(vector<pair<int,int>>& vt,vector<int>& dsuf, int V){
    
//     for(auto pair:vt){
        
//         int fromP = find(dsuf,pair.first);
//         int toP= find(dsuf,pair.second);

//         if(fromP==toP){
//             return true;
//         }
//         unionDS(dsuf,fromP,toP);
//     }
//     return false;
// }


// //using Disjoint Set (With Path Compression and Union by Rank)
// struct node{
//     int parent;
//     int rank;
// };

// int find1(vector<node>& dsuf1, int element){
//     if(dsuf1[element].parent==-1){
//         return element;
//     }else{
//         return dsuf1[element].parent = find1(dsuf1,dsuf1[element].parent);
//     }
// }

// void unionDS1(vector<node>& dsuf1, int fromP, int toP){

//     if(dsuf1[fromP].rank > dsuf1[toP].rank){
//         dsuf1[toP].parent = fromP;
//     }else if(dsuf1[fromP].rank < dsuf1[toP].rank){
//         dsuf1[fromP].parent = toP;
//     }else{
//         dsuf1[fromP].parent = toP;   
//         dsuf1[toP].rank +=1;
//     }
    
// }


// bool detectCycle1(vector<pair<int,int>>& vt, vector<node>& dsuf1, int V){
//     for(auto pair:vt){
        
//         int fromP = find1(dsuf1,pair.first);
//         int toP= find1(dsuf1,pair.second);

//         if(fromP==toP){
//             return true;
//         }
//         unionDS1(dsuf1,fromP,toP);
//     }
//     return false;    
// }



// int main(){

    
//     int V=5;
//     vector<pair<int,int>> vt;
//     vt.push_back({0,1});
//     vt.push_back({1,2});
//     vt.push_back({2,3});
//     vt.push_back({3,0});

//     vector<int> dsuf (V,-1);

//     if(detectCycle(vt,dsuf,V)){
//         cout<<"Graph 1 contains a cycle.";
//     }else{
//         cout<<"Graph 1 does not contain a cycle.";
//     }

//     vector<node> dsuf1;

//     dsuf.resize(V); 

//     for(int i=0;i<V;i++){
//         dsuf1[i].parent = -1;
//         dsuf1[i].rank = 0;
//     }

//     if(detectCycle1(vt,dsuf1,V)){
//         cout<<"Graph 2 contains a cycle.";
//     }else{
//         cout<<"Graph 2 does not contain a cycle.";
//     }
// }




//detect cycle undirected with BFS
void addEdge(vector<int> adjList[], int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}


bool isCycleBFSUtil(vector<int> adjList[], vector<int>& visited, int V, int node){
    queue<pair<int,int>> q;

    visited[node] = 1;
    q.push({node,-1});

    while(!q.empty()){
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adjList[curr]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,curr});
            }else if(parent!=it){
                return true;
            }
        }
    }

    return false;
}

bool isCycleBFS(vector<int> adjList[], int V){
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(isCycleBFSUtil(adjList, visited, V, i)){
                return true;
            }
        }
    }
    return false;
}




//detect cycle undirected with DFS
bool isCycleDFSUtil(vector<int> adjList[], int parent, vector<int>& visited, int V, int node){
    visited[node]=1;
    for(auto it : adjList[node]){
        if(!visited[it]){
            if(isCycleDFSUtil(adjList,node,visited,V,it)){
                return true;
            }
        }else if(it != parent){
            return true;
        }
    }
    return false;
}


bool isCycleDFS(vector<int> adjList[], int V){
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(isCycleDFSUtil(adjList,-1, visited, V, i)){
                return true;
            }
        }
    }
    return false;
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
    addEdge(adjList,9,10);
    // addEdge(adjList,10,5);

    bool ansbfs = isCycleBFS(adjList, V);

    bool ansdfs = isCycleDFS(adjList, V);

    if(ansbfs){
        cout<<"The Graph contains a cycle."<<endl;
    }else{
        cout<<"Graph does not contain a cycle."<<endl;
    }

    
    if(ansdfs){
        cout<<"The Graph contains a cycle.";
    }else{
        cout<<"Graph does not contain a cycle.";
    }
}