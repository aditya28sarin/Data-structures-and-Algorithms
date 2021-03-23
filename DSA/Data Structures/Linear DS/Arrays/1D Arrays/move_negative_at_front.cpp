// An input_array contains both positive and negative numbers in random order. 
//Reinput_arrayange the input_array elements so that all negative numbers appear before all positive numbers.
// Examples : 

// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5



-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;


void sortedInputArray(int start, int end, int *input_array)
{
    
    while(start<=end)
    {
        if(input_array[start]<0 && input_array[end]<0)
            start++;
        
        if(input_array[start]>0 && input_array[end]>0)
            end--;
        
        if((input_array[start]>0 && input_array[end]<0) || (input_array[start]<0 && input_array[end]>0))
        {
            int temp=input_array[start];
            input_array[start]=input_array[end];
            input_array[end]=temp;
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
        cin>>size_of_array;

        int input_array[size_of_array];
        
        for(int i=0;i<size_of_array;i++)
        {
            cin>>input_array[i];
        }

        sortedInputArray(0,size_of_array-1,input_array);

        for(int i=0;i<size_of_array;i++)
        {
            cout<<input_array[i]<<" ";
        }
    }
}