// #include<bits/stdc++.h>
// using namespace std;

// class Graph{
// public:
// 	int vertex;

// 	list<int> *adjList;

// 	Graph(int v)
// 	{
// 		vertex=v;
// 		adjList=new list<int>[v]; 
// 	}

// 	void addVertex(int u, int v, bool bidr=true)
// 	{
// 		adjList[u].push_back(v);
		
// 		if(bidr)
// 		{
// 			adjList[v].push_back(u);
// 		}
// 	}	
 
// 	void printAdjList()
// 	{
// 		for(int i=0;i<vertex;i++)
// 		{
// 			cout<<i<<"->";
// 			for(int node:adjList[i])
// 			{
// 				cout<<node<<",";
// 			}
// 			cout<<endl;
// 		}
// 	}

//     void BFS(int start)
//     {
//         queue<int> q;

//         bool *visited = new bool[vertex+1]{0};

//         q.push(start);
//         visited[start]=true;

//         while(!q.empty())
//         {
//             int temp = q.front();
//             cout<<temp<<" ";
//             q.pop();

//             for(int neighbor: adjList[temp])
//             {
//                 if(!visited[neighbor])
//                 {
//                     q.push(neighbor);
//                     visited[neighbor]=true;
//                 }
//             }
//         }
//     }
// };


// int main()
// {
// 	Graph g(6);

// 	g.addVertex(0,1);
// 	g.addVertex(1,2);
// 	g.addVertex(0,4);
// 	g.addVertex(2,4);
// 	g.addVertex(3,2);
// 	g.addVertex(2,3);
// 	g.addVertex(3,5);

// 	//g.printAdjList();	
// 	g.BFS(0);
// }





//map style 

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

    void BFS(int start)
    {
        queue<int> q;
        bool *visited=new bool[adjList.size()+1]{0};
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
                }
            }
        }
    }

};


int main()
{

    Graph g;


    g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.addEdge(3,5);

    g.printList();

    g.BFS(0);
}