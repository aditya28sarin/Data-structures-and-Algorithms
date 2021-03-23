#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int parent;
    int rank;
};

class Edge
{
public:
    int start;
    int end;
    int weight;
};


int find(int v, vector<Node> &dsuf)
{
    if(dsuf[v].parent==-1)
        return v;
    
    return dsuf[v].parent=find(dsuf[v].parent,dsuf);
}

void Union(int fromP, int toP, vector<Edge> &mst,  vector<Node> &dsuf)
{
	if(dsuf[fromP].rank > dsuf[toP].rank)
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	
		dsuf[fromP].parent = toP;
	else
	{
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		
	}
}

bool comparator(Edge a, Edge b)
{
    return a.weight<b.weight;
}

void Kruskals(vector<Edge> &edgeList, int vertices, int edges,vector<Edge> &mst,  vector<Node> &dsuf)
{
    sort(edgeList.begin(),edgeList.end(),comparator);

    int i=0,j=0;
    while(j<edges && i<vertices-1)
    {
        int start = find(edgeList[j].start, dsuf);
        int end = find(edgeList[j].end, dsuf);

        if(start==end)
        {
            j++;
            continue;
        }

        Union(start, end,mst, dsuf);
        mst.push_back(edgeList[j]);
        i++;
    }

}

void printMST(vector<Edge>& mst)
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.start<<"  dst: "<<p.end<<"  wt: "<<p.weight<<"\n";
}

int main()
{
    int edges,vertices;

    cin>>vertices>>edges;

    vector<Node> dsuf(vertices);
    vector<Edge> mst;
    for(int i=0;i<vertices;i++)
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    vector<Edge> edgeList;

    int start,end,wt;
    Edge e;
    for(int i=0;i<edges;i++)
    {
        cin>>start>>end>>wt;
        e.start=start;
        e.end=end;
        e.weight=wt;
        edgeList.push_back(e);
    }

    Kruskals(edgeList,vertices,edges,mst,dsuf);
	printMST(mst);
	

}
