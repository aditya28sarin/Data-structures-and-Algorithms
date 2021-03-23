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

    g.printList();

    g.BFS(0,5);
}