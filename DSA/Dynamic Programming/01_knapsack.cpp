
#include<iostream>
using namespace std;

//Top Down/ Memoization Approach 

// int knapSackUtil(int W, int wt[], int val[], int n, int** mem)
// {
//     if(W==0 || n==0)
//     return 0;
    
//     if(mem[W][n]!=-1)
//         return mem[W][n];
        
//     int result;
    
//     if(wt[n]>W)
//         result= knapSackUtil(W,wt,val,n-1, mem);
//     else
//         result= max(knapSackUtil(W-wt[n],wt,val,n-1, mem)+val[n],knapSackUtil(W,wt,val,n-1, mem));
        
//     return mem[W][n]=result;
// }


// int knapSack(int W, int wt[], int val[], int n) 
// { 
//    int** mem=new int*[n];
   
//    for(int i=0;i<n;i++)
// 	{
// 		mem[i]=new int[n];

// 		for(int j=0;j<n;j++)
// 		{
// 			mem[i][j]=-1; 
// 		}
// 	}
   
//    return knapSackUtil(W,wt,val,n,mem);
// }


//Bottom Up Approach 



int knapSack(int w, int wt[], int val[], int n){
    int dp[n+1][w+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }

            else if(wt[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }

            else
            {
                dp[i][j]=max(dp[i-1][j], val[i-1]+ dp[i-1][w-wt[i-1]]);
            }
        }
    }

    return dp[n][w];
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