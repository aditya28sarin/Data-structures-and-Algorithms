// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;

void firstLastOccurence(int arr[], int n, int &first, int &last, int element)
{
	if(n==0)
		return;

	if(arr[n]==element && first==-1)
		last=n;

	if(arr[n]==element)
		first=n;

	firstLastOccurence(arr,n-1,first,last, element);
}

int main()
{
	int size_of_array;
	cin>>size_of_array;
	
	int input_array[size_of_array];

	for(int i=0;i<size_of_array;i++)
	{
		cin>>input_array[i];
	}
	int element;
	cin>>element;
	int first=-1,last=0;
	firstLastOccurence(input_array,size_of_array-1,first,last,element);

	cout<<"The first ocurrence of "<<element<<" is at "<<first<<" and second is at "<<last;
	
}