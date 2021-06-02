
// //Strongly directed components --> Kosaraju Algorithm
// #include<bits/stdc++.h>
// using namespace std;
// class Graph{
// public:
// int vertex;

// list<int> *adjList;

// Graph()
// {

// }

// Graph(int v)
// {
//     vertex=v;
//     adjList=new list<int>[v];
// }


// void addEdge(int start, int end)
// {
//     adjList[start].push_back(end);
// }

// void DFSUtil(int node, bool visited[])
// {
//     visited[node]=true;
//     cout<<node<<" ";
    
//     list<int> :: iterator it;
//     for(it=adjList[node].begin();it!=adjList[node].end();++it)
//     {
//         if(!visited[*it])
//             DFSUtil(*it,visited);
//     }
// }


// Graph getTranspose()
// {

//     Graph g(vertex);
//     for(int i=0;i<vertex;i++)
//     {
//         list<int> :: iterator it;

//         for(it=adjList[i].begin();it!=adjList[i].end();++it)
//         {
//             g.adjList[*it].push_back(i);
//         }

//     }
//     return g;
// }

// void DFSModified(int node, bool visited[], stack<int> &st)
// {
//      visited[node]=true;

//     list<int> :: iterator it;
//     for(it=adjList[node].begin();it!=adjList[node].end();++it)
//     {
//         if(!visited[*it])
//             DFSModified(*it,visited,st);
//     }
//     st.push(node);
// }


// bool checkSSC()
// {
//     bool visited[vertex];
//     stack<int> st;
//     for(int i=0;i<vertex;i++)
//     {
//         visited[i]=false;
//     }

//     for(int i=0;i<vertex;i++)
//     {
//         if(visited[i]==false)
//             DFSModified(i,visited,st);
//     }
//     Graph gr=getTranspose();

//     for(int i=0;i<vertex;i++)
//     {
//         visited[i]=false;
//     }

//     while(!st.empty())
//     {
//         int v = st.top();
//         st.pop();

//         if(visited[v]==false)
//         {
//              gr.DFSUtil(v,visited);
//              cout<<endl;
//         }
//     }
// }

// };

// int main() 
// { 
//     // Create a graph given in the above diagram 
//     Graph g(5); 
//     g.addEdge(1, 0); 
//     g.addEdge(0, 2); 
//     g.addEdge(2, 1); 
//     g.addEdge(0, 3); 
//     g.addEdge(3, 4); 
  
//     cout << "Following are strongly connected components in "
//             "given graph \n"; 
//     g.checkSSC(); 
  
//     return 0; 
// } 

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v){
    adjList[u].push_back(v);
}

void findTopo(vector<int> adjList[], vector<int>& visited, stack<int>& st, int node){
    visited[node]=1;

    for(auto it : adjList[node]){
        if(!visited[it]){
            findTopo(adjList, visited, st, it);
        }
    }
    st.push(node);
}


void dfsans(vector<int> adjList[], vector<int>& visited, int node){
    cout << node << " "; 
    visited[node]=1;
    for(auto it : adjList[node]){
        if(!visited[it]){
            dfsans(adjList,visited,it);
        }
    }

}


int main(){
    int V = 5;
    vector<int> adjList[V+1];

    addEdge(adjList,1,2);
    addEdge(adjList,2,3);
    addEdge(adjList,3,1);
    addEdge(adjList,2,4);
    addEdge(adjList,4,5);

    stack<int> st;
    vector<int> visited(V,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            findTopo(adjList, visited, st, i);
        }
    }

    vector<int> transpose[V+1];

    for(int i=1;i<=V;i++){
        visited[i]=0;
        for(auto it : adjList[i]){
            transpose[it].push_back(i);
        }
    }

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            cout<<"SCC: ";
            dfsans(transpose, visited, node);
            cout<<endl;
        }
    }
}