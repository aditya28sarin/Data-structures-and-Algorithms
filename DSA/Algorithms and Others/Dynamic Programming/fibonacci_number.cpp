// URL: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include<iostream>
using namespace std;

int F[51];

int fibo(int n)
{
	if(F[n]!=-1)
		return F[n];
	else
		F[n]=fibo(n-1)+fibo(n-2);

	return F[n];
}

int main()
{

	for(int i=0;i<51;i++)
	{
		F[i]=-1;
	}

	F[0]=0;
	F[1]=1;
	int n;
	cin>>n;

	cout<<fibo(n);
}