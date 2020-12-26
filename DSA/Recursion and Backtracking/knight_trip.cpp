// URL: https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include<bits/stdc++.h>
using namespace std;


void displayBoard(int arr[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}


void knightProblem(int arr[5][5], int i, int j, int count)
{

	if(i<0 || j<0 || i>=5 || j>=5 || arr[i][j]!=0)
		return;

	else if(count==25)
	{
		arr[i][j]=count;
		displayBoard(arr);
		return;
	}

	arr[i][j]=count;

	knightProblem(arr,i+2,j+1,count+1);
	knightProblem(arr,i+2,j-1,count+1);
	knightProblem(arr,i-2,j+1,count+1);
	knightProblem(arr,i-2,j-1,count+1);
	knightProblem(arr,i+1,j+2,count+1);
	knightProblem(arr,i+1,j-2,count+1);
	knightProblem(arr,i-1,j+2,count+1);
	knightProblem(arr,i-1,j-2,count+1);

	arr[i][j]=0;
}


int main()
{

	int arr[5][5]={0};

	knightProblem(arr,0,0,1);
}