#include<bits/stdc++.h>
 using namespace std;
 
 
class Graph 
{ 
	int V; 
	list<int> *adj; 
    
    public: 
    
    Graph(int V) 
    { 
    	this->V = V; 
    	adj = new list<int>[V]; 
    } 
    
    void addEdge(int v, int w) 
    { 
    	adj[v].push_back(w);  
    
    } 
    
    
    void DFSUtil(int start, set<int> &st, stack<int> &st1)
    {
        st.insert(start);

    
        list<int> :: iterator it;
    
        for(it=adj[start].begin();it!=adj[start].end();++it)
        {
            if(st.find(*it)==st.end())
            {
                
                DFSUtil(*it,st,st1);
            }    
        }
        st1.push(start);
    }
    
    stack<int> DFS()
    {
        set<int> st;
        stack<int> st1;
        for(int i=0;i<V;i++)
        {
            if(st.find(i)==st.end())
            {
                DFSUtil(i,st,st1);
            }
        }
    
        return  st1;
    }
};


 int main()
 {
    Graph g(8); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(1, 3); 
	g.addEdge(2, 4); 
	g.addEdge(4, 7); 
	g.addEdge(4, 5); 
	g.addEdge(3, 5); 
	g.addEdge(5, 6);

    stack<int> st=g.DFS();

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
 }