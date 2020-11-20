#include<bits/stdc++.h>
using namespace std;
#define V 6



int minVertex(vector<int> &dist, vector<bool> &mistSet)
{
    int min = INT_MAX;
    int vertex;

    for(int i=0;i<V;i++)
    {
        if(mistSet[i]==false && dist[i]<min)
        {
            vertex=i;
            min=dist[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V])
{
    int parent[V];
    vector<int> dist(V,INT_MAX);
    vector<bool> mistSet(V,false);

    parent[0]=-1;
    dist[0]=0;

    for(int i=0;i<V-1;i++)
    {
        int u=minVertex(dist,mistSet);
        mistSet[u]=true;

        for(int j=0;j<V;j++)
        {
            /* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/

        if(graph[u][j]!=0 && mistSet[j]==false && graph[u][j]<dist[j])
        {
            dist[j]=graph[u][j];
            parent[j]=u;
        }
        }
    } 

    for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
    int graph[V][V]= { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

    findMST(graph);
    return 0;

}