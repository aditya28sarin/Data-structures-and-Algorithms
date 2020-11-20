
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size;
	cin>>size;

	int arr[size];
	
	int max=0;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	
	int repeat;
	cin>>repeat;
	int arr1[max]={0};


	for(int i=0;i<size;i++)
	{
		arr1[arr[i]]=arr1[arr[i]]+1;
	}
	int min = INT_MAX;
	for(int i=0;i<max;i++)
	{
		if(arr1[i]==repeat && i<min)
		{
			min =i;
		}
	}

	cout<<min;
}