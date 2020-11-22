// Given a sorted array of n uniformly distributed values arr[], write a function to search for a 
// particular element x in the array.

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

//searching an element in the input array using interpolation search algorithm 
int interpolationSearch(int input_array[], int key, int lower_index, int higher_index)
{
    while(lower_index<=higher_index)
    {
        int pos= lower_index + ((key-input_array[lower_index])*(higher_index-lower_index)/(input_array[higher_index]-input_array[lower_index]));

        if(input_array[pos]==key)
        {
            return pos;
        }

        if(input_array[pos]>key)
        {
            higher_index=pos-1;

        }
        if(input_array[pos]<key)
        {
            lower_index=pos+1;
        }
    }
    return -1;
}


int main()
{
    int input_cases;
    cin>>input_cases;

    while(input_cases--)
    {
        int size_of_array,key;
        cin>>size_of_array>>key;
        int input_array[size_of_array];

        for(int i=0;i<size_of_array;i++)
        {
            cin>>input_array[i];
        }

      	cout<<interpolation_search(input_array,key,0,size_of_array-1)<<endl;
    }
}
