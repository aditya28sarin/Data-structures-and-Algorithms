// URL: https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include<bits/stdc++.h>
using namespace std;


bool isValid(int arr[][5], int i, int j)
{
	return (i>=0 && j>=0 && i<5 && j<5 && arr[i][j]==0);
}

void knightProblem(int arr[][5], int i, int j)
{
	static int count = 0;

	if(!isValid(arr,i,j))
		return;

	count++;

	arr[i][j]=count;

	knightProblem(arr,i+2,j+1);
	knightProblem(arr,i+2,j-1);
	knightProblem(arr,i-2,j+1);
	knightProblem(arr,i-2,j-1);
	knightProblem(arr,i+1,j+2);
	knightProblem(arr,i+1,j-2);
	knightProblem(arr,i-1,j+2);
	knightProblem(arr,i-1,j-2);
}

int main()
{
		int maze[5][5]  =  {
	   {0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0}
	};

	knightProblem(maze,0,0);

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<maze[i][j]<<" ";
		}

		cout<<"\n";
	}
}