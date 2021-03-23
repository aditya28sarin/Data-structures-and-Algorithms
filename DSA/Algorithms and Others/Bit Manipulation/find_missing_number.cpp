// Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4
// Example 2:

// Input:
// N = 10
// A[] = {1,2,3,4,5,6,7,8,10}
// Output: 9



-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;


int findMissingElement(int input_array[], int size_of_array)
{
    int xor_array_elements=input_array[0];

    // xor all array elements from index 0 to size-1
    for(int i=1;i<size_of_array;i++)
    {
        xor_array_elements=xor_array_elements^input_array[i];
    }

    int xor_compare=1;

    for(int i=2;i<=size_of_array+1;i++)
    {
        xor_compare=xor_compare^i;
    }
    return (xor_compare^xor_array_elements);

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

    cout<<findMissingElement(input_array, size_of_array);

}