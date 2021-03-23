// Given an array arr[] of size N, check if it is sorted in non-decreasing order or not. 

// Example 1:

// Input:
// N = 5
// Arr[] = {10, 20, 30, 40, 50}
// Output: 1
// Explanation: The given array is sorted.
// Example 2:

// Input:
// N = 6
// Arr[] = {90, 80, 100, 70, 40, 30}
// Output: 0
// Explanation: The given array is not sorted.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

int main()
{

    int no_of_cases;

    cin>>no_of_cases;

    while(no_of_cases--)
    {

        int size_of_array;
        cin>>size_of_array;

        int input_array[size_of_array],count=0;

        for(int i=0;i<=size_of_array-1;i++)
        {
            cin>>input_array[i];
        }


        for(int i=0;i<=size_of_array-2;i++)
        {
            if(input_array[i+1]>=input_array[i])
            {
                count++;
            }
        }

        if(count==size_of_array-1)
        {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}



