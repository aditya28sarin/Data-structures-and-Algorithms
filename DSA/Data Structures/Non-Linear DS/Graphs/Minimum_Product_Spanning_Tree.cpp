#include<bits/stdc++.h>
using namespace std;



int findMin(int vertices,  vector<int> dist, vector<bool> mistSet)
{
    int min = INT_MAX;
    int index;
    for(int i=0;i<vertices;i++)
    {
        if(mistSet[i]==false && dist[i]<min)
        {
            min=dist[i];
            index=i;
        }
    }

    return index;
}

void printMST(int vertices,int adjMat[][6], int parent[6])
{
    printf("Edge   Weight\n"); 
    int minProduct = 1; 
    for (int i = 1; i < vertices; i++) { 
        printf("%d - %d    %d \n", 
               parent[i], i, adjMat[i][parent[i]]); 
  
        minProduct *= adjMat[i][parent[i]]; 
    } 
    printf("Minimum Obtainable product is %d\n", 
           minProduct); 
}

void primMST(int vertices, int adjMat[][6])
{
    vector<int> dist(vertices,INT_MAX);
    vector<bool> mistSet(vertices,false);
    int parent[vertices];

    parent[0]=-1;
    dist[0]=0;

    for(int i=0;i<vertices-1;i++)
    {
        int min = findMin(vertices,dist, mistSet);

        mistSet[min]=true;

        for(int i=0;i<vertices;i++)
        {
            if(adjMat[min][i]>0 && mistSet[min]==false && adjMat[min][i]<dist[i])
            {
                parent[i]=min;
                dist[i]=adjMat[min][i];
            }
        }

    }
    printMST(vertices, adjMat, parent);

}


void logValue(int vertices, int adjMat[][6])
{
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            if (adjMat[i][j] > 0) 
                adjMat[i][j]=log(adjMat[i][j]);
            else
            {
                adjMat[i][j]=0;
            }
            
        }
    }
}

int main()
{
    int edges, vertices;

    cin>>vertices>>edges;

    int adjMat[vertices][vertices]={0};

    int start, end, weight;

    for(int i=0;i<edges;i++)
    {
        cin>>start>>end>>weight;
        adjMat[start][end]=weight;
        adjMat[end][start]=weight;
    }    

  logValue(vertices, adjMat);

  primMST(vertices, adjMat);
}