// URL: https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/

#include<iostream>
#include<vector>
using namespace std;

void printPath(int** arr, int** arr_util, int r, int c, int m, int n)
{
	//check if it is safe to traverse further
	if(r<0 || r>=m || c<0 || c>=n || arr_util[r][c]==1)
	{
		return;
	}

	//update the visited of current point
	arr_util[r][c]=1;

	//reached the end of the matrix
	if(r>=m-1 && c>=n-1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr_util[i][j]==1)
				{
					cout<<arr[i][j]<<" ";
				}
			}
		}
		cout<<endl;
	}
		
	printPath(arr,arr_util,r,c+1,m,n);

	printPath(arr,arr_util, r+1,c,m,n);

	arr_util[r][c]=0;	
}

int main()
{
	int m,n;
	cin>>m>>n;

	//input matrix
	int** arr=new int*[m];

	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}

	//matrix created to track visited values
	int** arr_util=new int*[m];

	for(int i=0;i<m;i++)
	{
		arr_util[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			arr_util[i][j]=0;
		}
	}

	printPath(arr,arr_util,0,0,m,n);

}

