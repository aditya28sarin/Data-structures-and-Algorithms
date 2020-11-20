//for undirected graph 
#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertex;

   map<int, list<int>> adjList;
    set<int> st;
    Graph()
    {

    }
    
    void addEdge(int u, int v, int bidir=true)
    {
        adjList[u].push_back(v);
 
        st.insert(u);
        st.insert(v);
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

    bool BFS(int start)
    {
        queue<int> q;
        bool *visited=new bool[adjList.size()+1]{0};
        q.push(start);
        visited[start]=true;
        bool flag=true;
        
        while(!q.empty())
        {
            int temp = q.front();
            if(st.find(temp)==st.end())
                flag=false;

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

        return flag;
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

   bool flag =  g.BFS(0);
    if(flag==true)
    {
        cout<<"\n\nStrongly Connected";
    }
    else
        cout<<"\n\nNot Strongly Connected";
    
}


//directed graph  --> Running BFS V Times to check if it covers all nodes in each run 
#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertex;

   map<int, list<int>> adjList;
   vector<int> vt;
    std::vector<int>::iterator it; 
    Graph()
    {

    }
    
    void addEdge(int u, int v, bool bidir)
    {
        adjList[u].push_back(v);
 
        vt.push_back(u);
         it = std::find (vt.begin(), vt.end(), v); 
        if (it == vt.end())  
            vt.push_back(v);
        
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

    void BFSUtil(int start, bool &flag)
    {
        queue<int> q;
        bool *visited=new bool[adjList.size()+1]{0};
        q.push(start);
        visited[start]=true;
        
        while(!q.empty())
        {
            int temp = q.front();
            it = std::find (vt.begin(), vt.end(), temp); 
            if (it == vt.end())  
                flag=false;

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

    void BFS(int start)
    {
        bool flag = true;

        for(int i=0;i<vt.size();i++)
        {
                BFSUtil(vt[i],flag);
                cout<<endl;
        }

        if(flag==true)
        {
            cout<<"Strongly Connected Graph";
        }
        else
        {
            cout<<"\nNot Strongly Connected Graph";
        }
        
    
    }
};


int main()
{

    Graph g;


    g.addEdge(0,1,false);
	g.addEdge(1,2,false);
	g.addEdge(2,4,false);
	g.addEdge(4,2,false);
	g.addEdge(2,3,false);
	g.addEdge(3,0,false);

    g.printList();

    g.BFS(0);
    
}


//directed graph  --> Kosaraju Algorithm
#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
int vertex;

list<int> *adjList;

Graph()
{

}

Graph(int v)
{
    vertex=v;
    adjList=new list<int>[v];
}


void addEdge(int start, int end)
{
    adjList[start].push_back(end);
}

void DFSUtil(int node, bool visited[])
{
    visited[node]=true;

    list<int> :: iterator it;
    for(it=adjList[node].begin();it!=adjList[node].end();++it)
    {
        if(!visited[*it])
            DFSUtil(*it,visited);
    }
}


Graph getTranspose()
{

     Graph g(vertex);
    for(int i=0;i<vertex;i++)
    {
        list<int> :: iterator it;

        for(it=adjList[i].begin();it!=adjList[i].end();++it)
        {
            g.adjList[*it].push_back(i);
        }

    }
    return g;
}


bool checkSC()
{
    bool visited[vertex];
    
    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }


    DFSUtil(0,visited);

    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
            return false;
    }

    Graph gr=getTranspose();

    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }


    gr.DFSUtil(0,visited);

    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
            return false;
    }


    return true;
}
};

int main() 
{ 
    Graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(1, 2); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 0); 
    g1.addEdge(2, 4); 
    g1.addEdge(4, 2); 
    g1.checkSC()? cout << "Yes\n" : cout << "No\n"; 
  
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.checkSC()? cout << "Yes\n" : cout << "No\n"; 
  
    return 0; 
} 