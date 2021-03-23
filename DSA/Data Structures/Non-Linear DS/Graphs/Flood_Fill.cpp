#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];
bool visited[1000][1000];

void floodFill(int m,int n, int x, int y, int newColor);
void floodFillUtil(int m, int n, int x, int y, int newColor, int oldColor);

int main() 
{
	
    int cases;
	cin>>cases;
	
	while(cases--)
	{ 
	    int m,n;
	    cin>>m>>n;
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    
	    int x,y,newColor;
	    cin>>x>>y>>newColor;
	    
	    floodFill(m,n,x,y,newColor);
	    
	}
}

void floodFillUtil(int m, int n, int x, int y, int newColor, int oldColor)
{
    if(arr[x][y]!=oldColor || visited[x][y]==true || x<0 ||  y<0 || x>=m ||y>=n)
        return;

    visited[x][y]=true;

    arr[x][y]=newColor;

    floodFillUtil(m,n,x-1,y,newColor,oldColor);
    floodFillUtil(m,n,x+1,y,newColor,oldColor);
    floodFillUtil(m,n,x,y-1,newColor,oldColor);
    floodFillUtil(m,n,x,y+1,newColor,oldColor);
}

void floodFill(int m,int n, int x, int y, int newColor)
{
    bool visited[m][n]{false};
    int oldColor=arr[x][y];

    if(!visited[x][y])
        floodFillUtil(m,n,x,y,newColor,oldColor);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
  
    cout<<endl;
}
