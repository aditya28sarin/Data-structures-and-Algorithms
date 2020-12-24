// URL: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

#include<bits/stdc++.h>
using namespace std;



bool canMove(int arr[][5], int i, int j, bool visited[][5])
{
	

	return (i>=0 && j>=0 && i<5 && j<5 && arr[i][j]==1 && visited[i][j]==false);
}

int shortestPathUtil(int arr[][5], int i, int j, int x, int y, bool visited[][5])
{
	if(!canMove(arr,i,j,visited))
		return 1000;

	if(i==x && j==y)
		return 0;

	visited[i][j]=true;

	int left = shortestPathUtil(arr,i,j-1,x,y,visited) + 1;
	int bottom = shortestPathUtil(arr,i+1,j,x,y,visited) + 1;
	int right = shortestPathUtil(arr,i,j+1,x,y,visited) + 1;
	int top = shortestPathUtil(arr,i-1,j,x,y,visited) + 1;

	visited[i][j]=false;

	return min(min(left,bottom), min(right, top));
}


int shortestPath(int arr[][5], int i, int j, int x, int y)
{
	bool visited[5][5]={false};

	int min_dist = shortestPathUtil(arr,i,j,x,y,visited);

	return min_dist;
}

int main()
{
		int maze[5][5]  =  {
	   {1, 0, 0, 0, 0},
	   {1, 1, 0, 1, 0},
	   {0, 1, 1, 1, 0},
	   {0, 0, 0, 1, 0},
	   {1, 1, 1, 1, 1}
	};

	cout<<shortestPath(maze,0,0,4,4);
}