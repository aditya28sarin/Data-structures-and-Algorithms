// URL: https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/save-patients/description/

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}


int main()
{
	int vaccines;
	cin>>vaccines;

	int vaccine_strength[vaccines],people_Strength[vaccines];
	for(int i=0;i<vaccines;i++)
	{
		cin>>vaccine_strength[i];
	}
	
	for(int i=0;i<vaccines;i++)
	{
		cin>>people_Strength[i];
	}

	bubbleSort(vaccine_strength,vaccines);
	bubbleSort(people_Strength,vaccines);

	bool flag=true;

	int i=0;
	while(i<vaccines)
	{
		if(vaccine_strength[i]!=people_Strength[i])
			flag=false;
		i++;
	}

	if(flag)
		cout<<"Yes";
	else
		cout<<"No";	
}