// URL: https://www.geeksforgeeks.org/program-check-array-sorted-not-iterative-recursive/

#include<bits/stdc++.h>
using namespace std;

bool checkSorted(int arr[], int n, bool &checkIf)
{
	if(n==0)
	{
		return checkIf;
	}

	if(arr[n]<arr[n-1])
	{
		checkIf=false;
	}

	return checkSorted(arr,n-1,checkIf);
}

int main()
{
	int size_of_array;
	cin>>size_of_array;
	bool checkIf=true;
	int input_array[size_of_array];

	for(int i=0;i<size_of_array;i++)
	{
		cin>>input_array[i];
	}


	if(checkSorted(input_array,size_of_array-1,checkIf))
	{
		cout<<"Array is Sorted"<<endl;
	}
	else
	{
		cout<<"Array is not sorted"<<endl;
	}
}