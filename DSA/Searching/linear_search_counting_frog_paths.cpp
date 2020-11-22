#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,s,t;
	cin>>x>>y>>s>>t;

	int x_max=x+s;
	int y_max=y+s;
	int count=0;
	for(int i=x;i<=x_max;i++)
	{
		for(int j=y;j<=y_max;j++)
		{
			if((i+j)<=t)
			{
				//cout<<i<<" "<<j<<" ";
				count++;
				//cout<<count<<endl;
			}
		}
	}
	cout<<count;
}