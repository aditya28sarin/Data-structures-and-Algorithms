// URL: https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

#include<iostream>
using namespace std;

bool isSafe(int **arr, int row, int col, int n)
{
	//to check if a queen is placed in a particular column in each row(find queen upwards)
	for(int i=0;i<row;i++)
	{
		if(arr[i][col]==1)
			return false;
	}

	//to check for any queen on left back diagonal
	int i=row,j=col;

	while(i>=0 && j>=0)
	{
		if(arr[i][j]==1)
		{
			return false;
		}

		i--;
		j--;
	}

	//to check for any queen on right back diagonal
	i=row;
	j=col;
	while(i>=0 && j<n)
	{
		if(arr[i][j]==1)
		{
			return false;
		}
		i--;
		j++;
	}

	return true;
}


bool nQueen(int** arr, int row, int n)
{
	///we have successfully placed 'n' queens, now print matrix 
	if(row==n)
	{
        return true;
	}

	//for each column
	for(int i=0;i<n;i++)
	{
		if(isSafe(arr,row,i,n))
		{
			arr[row][i]=1;

			//check for subsequent rows once this queen is palced
			if(nQueen(arr,row+1,n))
			{
				return true;
			}

			//if not then we backtrack and put it 0
			arr[row][i]=0;
		}
	}

	return false;
}

int main()
{
	int n;
	cin>>n;

	int** arr= new int*[n];

	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];

		for(int j=0;j<n;j++)
		{
			arr[i][j]=0; 
		}
	}

	if(nQueen(arr,0,n))
	{
		for(int i=0;i<n;i++)
		{

			for(int j=0;j<n;j++)
			{
				cout<<arr[i][j]<<" "; 
			}
			cout<<"\n";
		}
	}
}
