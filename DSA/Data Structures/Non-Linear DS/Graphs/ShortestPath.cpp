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

    void BFS(int start, int end)
    {
        queue<int> q;

        bool *visited = new bool[vertex+1]{0};
        int *parent = new int[vertex+1]{-1};
        int *distance = new int[vertex+1]{0};

        q.push(start);
        visited[start]=true;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(auto neighbor : adjList[temp]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                    parent[neighbor]=temp;
                    distance[neighbor]=distance[temp]+1;
                }
            }
        } 
        
        cout<<"Shortest path from "<<start<<"to "<<end<<" is:"<<distance[end]<<endl;

        int val = end;
        while(val!=-1){
            cout<<val<<"->";
            val=parent[val];
        }
    }
};


int main()
{
	Graph g(6);

	g.addVertex(0,1);
	g.addVertex(1,2);
	g.addVertex(0,4);
	g.addVertex(2,4);
	g.addVertex(3,2);
	g.addVertex(2,3);
	g.addVertex(3,5);
    g.addVertex(3,4);
    

	//g.printAdjList();	
	g.BFS(0,5);
}



