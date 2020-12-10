#include<bits/stdc++.h>
using namespace std;

int knapsackProblem(int value[], int wt[], int n, int W)
{
	if(n==0 || W==0)
	{
		return 0;
	}

	if(wt[n-1]>W)
		return knapsackProblem(value,wt,n-1,W);

	return max(knapsackProblem(value, wt, n-1, W-wt[n-1])+value[n-1],knapsackProblem(value,wt,n-1,W));
}


int main(){


	int value[3]={100,50,150};
	int wt[3]={10,20,30};
	int W=50;
	cout<<knapsackProblem(value,wt,3,W)<<endl;
}
