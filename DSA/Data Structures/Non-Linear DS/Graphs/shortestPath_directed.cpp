void findTopoSort(vector<int> adjList[], vector<int>& visited, stack<int>& st, int node){
    visited[node]=1;

    for(auto el:adjList[node]){
        if(!visited[el.first]){
            findTopoSort(adjList,visited,st,el.first);
        }
    }

    st.push(node);
}

shortestPathDirected(vector<pair<int,int>> adjLsit[], int V, int src){
    vector<int> visited(V+1,0);
    stack<int> st;

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            findTopoSort(adjList,visited,st,i);
        }
    }


    vector<int> distance(V,INT_MAX);

    distance[src]=0;


    while(!st.empty()){
        int temp=st.top();
        st.pop();

        for(auto el:adjList[temp]){
            if(distance[el.first]>distance[temp]+el.second){
                distance[el.first]=distance[temp]+el.second;
            }
        }
    }
}


void findTopoSort(vector<pair<int,int>> adjList[], vector<int>& visited, int V, stack<int>& st, int curr){
    visited[curr]=1;

    for(auto it : adjList[curr]){
        if(!visited[it.first]){
            findTopoSort(adjList,visited,V,st,it.first);
        }
    }

    st.push(curr);
}

void shortestPath(vector<pair<int,int>> adjList[], int V, int src){
    stack<int> st;
    vector<int> distance(V+1,INT_MAX);
    vector<int> visited (V+1,0);

    for(int i=0;i<=V;i++){
        if(!visited[i]){
            findTopoSort(adjList,visited,V,st,i);
        }
    }
}