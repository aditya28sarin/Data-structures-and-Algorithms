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

	void addVertex(int u, int v, bool bidr)
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
        int *distance=new int[vertex+1]{0};
        int *parent=new int[vertex+1];
    
        for(int i=0;i<vertex;i++)
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

            for(int neighbor: adjList[temp])
            {
                if(!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor]=true;
                    distance[neighbor]=distance[temp]+1;
                    parent[neighbor]=temp;
                }
            }
        }
        cout<<endl<<endl;
        
        for(int i=0;i<vertex;i++)
        {
            cout<<i<<"node having" <<distance[i]<<endl;
        }

        cout<<"Shortest distance is "<<distance[end]<<endl;

        cout<<"Shortest path is ";

        int var=end;
        while(var!=-1)
        {
            cout<<var<<"->";
            var=parent[var];
        }
    }
};


int main()
{
	Graph g(50);

    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;

    for(int u=0;u<36;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
                int v = u + dice + board[u+dice];
                g.addVertex(u,v,false);
        }
    
    }
	//g.printAdjList();	
	g.BFS(0,36);
}














