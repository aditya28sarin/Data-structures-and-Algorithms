// Given an array of integers, your task is to find the smallest and second smallest element
//in the array. If smallest and second smallest do not exist, print -1.

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
//Each test case contains an integer n denoting the size of the array. 
//Then following line contains 'n' integers forming the array.

// Output:
// Print the smallest and second smallest element if possible,else print -1.

// Constraints:
// 1<=T<=100
// 1<=n<=100
// 1<=a[i]<=1000

// Example:
// Input :
// 3
// 5
// 2 4 3 5 6
// 6
// 1 2 1 3 6 7
// 2
// 1 1
// Output :
// 2 3
// 1 2
// -1


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
void sortingArray(int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        int temp=arr[i];
        for(int j=i;j<n;j++)
        {
        if(arr[j]<=temp)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        }
    }
}

int main()
{
    int no_of_cases;
    cin>>no_of_cases;

    while(no_of_cases--)
    {
        int size_of_array;
        cin>> size_of_array;
        
		int input_array[size_of_array],cp=0;

        for(int i=0;i<size_of_array;i++)
        {
            cin>>input_array[i];
        }
        sortingArray(input_array,size_of_array);
		 int t=0;
		 while(input_array[t]==input_array[0])
		 {
			t++;
		 }

		 if(t==n){
			cout<<-1;
		 }
		 else{
			cout<<input_array[0]<<" "<<input_array[t]<<endl;
		 }
	}
}
