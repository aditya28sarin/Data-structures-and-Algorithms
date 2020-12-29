// URL: https://www.geeksforgeeks.org/coin-change-dp-7/

#include<bits/stdc++.h>
using namespace std;


int coinChange(vector<int> &coins, int amount)
{

	int n = coins.size();
	int table[n+1][amount+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=amount;j++)
		{
			if(j==0)
			{
				table[i][j]=0;
			}
			
			else if(i==0)
			{
				table[i][j]=1e5;
			}
			
			else if(coins[i-1]>j)
				table[i][j]=table[i-1][j];
			
			else
			{
				table[i][j]=min(table[i-1][j], 1+table[i][j-coins[i-1]]);
			}
		}
	}

	return table[n][amount]>1e4?-1:table[n][amount];
}

int main()
{
	int amount;
	cout<<"Enter the amount"<<endl;
	cin>>amount;

	vector<int> coins{1,2,5};

	cout<<coinChange(coins,amount);
}

