// Given an array, write functions to find the minimum and maximum elements in it. 

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

int findMaxOfArray(int arr[],int index,int size)
{
    static int max = arr[0];
    
    if(index==size)
        return max;
    
    if(arr[index]>max)
        max=arr[index];
    
    return findMaxOfArray(arr,index+1,size);
}

int main()
{
    int arr_size;
    cin>>arr_size;
    
    int input_array[arr_size];
    for(int i=0;i<arr_size;i++)
    {
        cin>>input_array[i];
    }
    
    int max = findMaxOfArray(input_array,0,arr_size);
    
    cout<<max;
    
    return 0;
}