#include<bits/stdc++.h>
using namespace std;

int findPower(int base, int power)
{
	if(power==0)
	{
		return 1;
	}

	int prevPower=findPower(base, power-1);
	return base*prevPower;
}


int main()
{
	int base,power;
	
	cin>>base>>power;

	cout<<findPower(base, power);
}
