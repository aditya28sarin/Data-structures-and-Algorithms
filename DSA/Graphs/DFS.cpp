#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
    int vertex;

   map<int, list<int>> adjList;

    Graph()
    {

    }
    
    void addEdge(int u, int v, int bidir=true)
    {
        adjList[u].push_back(v);

        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printList()
    {       
        for(auto row: adjList)
        {
      
            int key = row.first;
            cout<<key<<"->";

            for(auto row_contents:row.second)
            {
                cout<<row_contents<<",";
            }
            cout<<endl;
        }
    }

    void BFS(int start, int end)
    {
        queue<int> q;
        bool *visited=new bool[adjList.size()+1]{0};
        int *parent =new int[adjList.size()+1];
        int *distance =new int[adjList.size()+1]{0};
        
        
        for(int i=0;i<adjList.size();i++)
        {
            parent[i]=-1;
        }
        q.push(start);
        visited[start]=true;
        while(!q.empty())
        {
            int temp = q.front();
            cout<<temp<<" ";
             q.pop();

            for(auto val : adjList[temp])
            {
                if(!visited[val])
                {
                    q.push(val);
                    visited[val]=true;
                    parent[val]=temp;
                    distance[val]=distance[temp]+1;
                }
            }
        }
        
        cout<<endl<<endl;
        
        for(int i=0;i<adjList.size();i++)
        {
            cout<<i<<"node having" <<distance[i]<<endl;
        }
        
        cout<<"Shortest distance is "<<distance[end]<<endl;

        cout<<"Shortest path is ";
        
        int var = end;
        
        while(var!=-1)
        {
            cout<<var<<"->";
            var=parent[var];
        }

    }
    

//iterative
void DFS(int start, int end, vector<int> &vt)
    {
        stack<int> st;
        bool *visited=new bool[adjList.size()+1]{0};


        st.push(start);
        visited[start]=true;
        
        std::vector<int>::iterator it; 
        
        while(!st.empty())
        {
            int temp=st.top();
             st.pop();
            
            if(!visited[temp])
            {
                vt.push_back(temp); 
                visited[temp]=true;
            }

            for(auto rowel : adjList[temp])
            {
                 if(!visited[rowel])
                {
                    st.push(rowel);
                    visited[rowel]=true;
                }
            }
        }
    }


//recursive
void dfsUtil(vector<int> g[], bool visited[],int node,vector<int> &ans)
{
    
    visited[node]=true;
    
    ans.push_back(node);
    
    vector<int> ::iterator it;
    
     for(it=g[node].begin();it!=g[node].end();++it)
        {
            if(!visited[*it])
            {
                dfsUtil(g,visited,*it,ans);
            }
        }
}

vector <int> dfs(vector<int> g[], int N)
{
    bool *visited=new bool[N]{0};
    
    vector<int> ans;
    
    for (int i = 0; i < V; i++) 
        if (visited[i] == false)
             dfsUtil(g,visited,0,ans);
    
    return ans;
}

};

int main()
{

    Graph g;


    g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(1,5);
	g.addEdge(1,6);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(4,6);
	
	g.addEdge(4,3);

    g.printList();

    g.BFS(0,5);
    
    cout<<endl<<endl;
    vector<int> vt;
    g.DFS(0,5,vt);

    for(int i=0;i<vt.size();i++)
    {
        cout<<vt[i]<<" ";
    }
}



//recursive better version 

#include<bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj; 
	void DFSUtil(int v, bool visited[]); 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void DFS(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);  
//	adj[w].push_back(v);
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	
	visited[v] = true; 
	cout << v << " "; 

	
	list<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		if(!visited[*i]) 
			DFSUtil(*i, visited); 
} 

void Graph::DFS() 
{ 
	bool *visited = new bool[V]{0}; 

	
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			DFSUtil(i, visited); 
} 

int main() 
{ 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is Depth First Traversal\n"; 
	g.DFS(); 

	return 0; 
} 
