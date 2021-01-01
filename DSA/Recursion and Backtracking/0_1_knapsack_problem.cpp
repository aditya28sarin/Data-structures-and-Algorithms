// URL: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<bits/stdc++.h>
using namespace std;

int knapSackUtil(int W, int wt[], int val[], int n, int** mem)
{
    if(W==0 || n==0)
    return 0;
    
    if(mem[W][n]!=-1)
        return mem[W][n];
        
    int result;
    
    if(wt[n]>W)
        result= knapSackUtil(W,wt,val,n-1, mem);
    else
        result= max(knapSackUtil(W-wt[n],wt,val,n-1, mem)+val[n],knapSackUtil(W,wt,val,n-1, mem));
        
    return mem[W][n]=result;
}


int knapSack(int W, int wt[], int val[], int n) 
{ 
   int** mem=new int*[n];
   
   for(int i=0;i<n;i++)
	{
		mem[i]=new int[n];

		for(int j=0;j<n;j++)
		{
			mem[i][j]=-1; 
		}
	}
   
   return knapSackUtil(W,wt,val,n,mem);
}



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}