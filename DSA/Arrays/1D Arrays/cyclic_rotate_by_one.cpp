// Given an array, cyclically rotate an array by one.

// Input:
// The first line of input contains an integer T denoting the number of test cases.
//Then T test cases follow. Each test case contains an integer n denoting the size of the array.
//Then following line contains 'n' integers forming the array. 

// Output:
// Output the cyclically rotated array by one.

// Constraints:
// 1<=T<=1000
// 1<=N<=1000
// 0<=a[i]<=1000

// Example:
// Input:
// 2
// 5
// 1 2 3 4 5
// 8
// 9 8 7 6 4 2 1 3

// Output:
// 5 1 2 3 4
// 3 9 8 7 6 4 2 1


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int no_of_cases;
    cin>>no_of_cases;

    while(no_of_cases--)
    {

        int size_of_array;
        cin>>size_of_array;

        int input_array[size_of_array],temp_array[size_of_array];

        for (int i=0;i<size_of_array;i++)
        {

            cin>>input_array[i];
        }
        int temp=input_array[n-1];
        for(int i=1;i<size_of_array;i++)
        {
            temp_array[i]=input_array[i-1];
        }
            input_array[0]=temp;
        for(int i=0;i<size_of_array;i++)
        {
            cout<<temp_array[i]<<" ";
        }
        cout<<endl;
    }
}   



