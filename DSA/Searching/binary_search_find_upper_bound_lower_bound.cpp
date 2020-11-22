// Given a sorted array arr[] of N integers and a number K, the task is to write the C program to find the upper_bound() and lower_bound() of K in the given array.

// Examples:

// Input: arr[] = {4, 6, 10, 12, 18, 20}, K = 6
// Output:
// Lower bound of 6 is 6 at index 1
// Upper bound of 6 is 10 at index 2

// Input: arr[] = {4, 6, 10, 12, 18, 20}, K = 20
// Output:
// Lower bound of 20 is 20 at index 5
// Upper bound doesn’t exist

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

//finds upper bound of input element within array using binary search 
int lowerBound(int lower_index, int higher_index, int input_array[], int input_element)
{

    if(lower_index>higher_index)
    {
        return lower_index;
    }

    int middle_index = lower_index + (higher_index-lower_index)/2;

    if(arr[m]>=element)
    {   
       return lowerBound(lower_index,middle_index-1,input_array,input_element);
    }
   
    return lowerBound(middle_index+1,higher_index,input_array,input_element);

}


//finds upper bound of input element within array using binary search 
int upperBound(int lower_index, int higher_index, int input_array[], int input_element)
{

    if(lower_index>higher_index)
    {
        return lower_index;
    }
        int middle_index = lower_index + (higher_index-lower_index)/2;
   
        if(arr[middle_index]<=input_element)
        {   
           return upperBound(middle_index+1,higher_index,input_array,input_element);
        }
        
       return upperBound(lower_index,middle_index-1,input_array,input_element);
 
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

    int input_element;
    cin>>input_element;

    cout<<"Lower bound of "<<input_element<<" is:"<<lowerBound(0,size_of_array-1,input_array, input_element)<<endl;
    cout<<"Upper bound of "<<input_element<<" is:"<<upperBound(0,size_of_array-1,input_array, input_element)<<endl;


}