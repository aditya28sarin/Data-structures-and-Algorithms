#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int vertex;

	list<int> *adjList;

	Graph(int v)
	{
		vertex=v;
		adjList=new list<int>[v]; 
	}

	void addVertex(int u, int v, bool bidr=true)
	{
		adjList[u].push_back(v);
		
		if(bidr)
		{
			adjList[v].push_back(u);
		}
	}	
 
	void printAdjList()
	{
		for(int i=0;i<vertex;i++)
		{
			cout<<i<<"->";
			for(int node:adjList[i])
			{
				cout<<node<<",";
			}
			cout<<endl;
		}
	}

void BFS(int start, int level)
    {
        queue<int> q;
      
        bool *visited = new bool[vertex+1]{0};

        q.push(start);
        visited[start]=true;
        int c[vertex]={0};
     
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(int neighbor: adjList[temp])
            {
                if(!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor]=true;
                    c[neighbor]=c[temp]+1;
                }
            }
        }
        
        for(int i=0;i<vertex;i++)
        {
            if(c[i]==level)
            {
                cout<<i<<" ";
            }
        }
    }
};


int main()
{
	Graph g(6);

	g.addVertex(0, 1); 
    g.addVertex(0, 2); 
    g.addVertex(1, 3); 
    g.addVertex(2, 4); 
    g.addVertex(2, 5); 

    g.BFS(0,2);
	
}

