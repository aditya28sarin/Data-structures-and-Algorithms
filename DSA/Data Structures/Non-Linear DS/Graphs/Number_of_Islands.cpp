#include<bits/stdc++.h>
using namespace std;
#define ROW 5 
#define COL 5


void countIslandsUtil(int M[][COL],int i, int j, bool visited[][COL]);
int countIslands(int M[][COL], bool visited[][COL])
{
    int count=0;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(M[i][j]==1 && visited[i][j]==false)
            {
                countIslandsUtil(M,i,j,visited);
                count++;
            }
        }
       
    }
    return count;
}

void countIslandsUtil(int M[][COL],int i, int j, bool visited[][COL])
{
    if(visited[i][j]==true || i<0 || j<0 || i>=ROW || j>=COL || M[i][j]==0)
        return;

    visited[i][j]=true;
    countIslandsUtil(M,i-1,j,visited);
    countIslandsUtil(M,i+1,j,visited);
    countIslandsUtil(M,i,j-1,visited);
    countIslandsUtil(M,i,j+1,visited);
    countIslandsUtil(M,i-1,j-1,visited);
    countIslandsUtil(M,i-1,j+1,visited);
    countIslandsUtil(M,i+1,j-1,visited);
    countIslandsUtil(M,i+1,j+1,visited);
}

int main() 
{ 
    bool visited[ROW][COL]{false};
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << countIslands(M,visited); 
  
    return 0; 
} 