// URL:https://www.geeksforgeeks.org/counting-sort/

#include<bits/stdc++.h>
using namespace std;


void countSort(int input_array[], int array_size)
{
	int max=input_array[0];
	for(int i=0;i<array_size;i++)
	{
		if(input_array[i]>max)
			max=input_array[i];
	}

	int count_array[max+1]={0};

	//filling the count array values
	for(int i=0;i<array_size;i++)
	{
		count_array[input_array[i]]++;
	}

	//modifying the count array
	for(int i=1;i<=max;i++)
	{
		count_array[i]=count_array[i]+count_array[i-1];
	}

	//this is our output array 
	int output_array[array_size];
	for(int i=array_size-1;i>=0;i--)
	{
		output_array[--count_array[input_array[i]]]=input_array[i];
	}

	//putting the final values inside the original array
	for(int i=0;i<array_size;i++)
	{
		input_array[i]=output_array[i];
	}

}

int main()
{
	int array_size;
	cin>>array_size;

	int input_array[array_size];
	for(int i=0;i<array_size;i++)
	{
		cin>>input_array[i];
	}

	countSort(input_array, array_size);

	for(int i=0;i<array_size;i++)
	{
		cout<<input_array[i]<<" ";
	}
}