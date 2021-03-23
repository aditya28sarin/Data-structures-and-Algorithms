// Given a set of numbers where all elements occur even number of times except one number, find the odd occurring number

#include<bits/stdc++.h>
using namespace std;


int findOddOccurence(int input_array[], int size_of_array)
{
    int res=0;
    for(int i=0;i<size_of_array;i++)
    {
        res=res^input_array[i];
    }
    return res;
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

    cout<<findOddOccurence(input_array, size_of_array);
}
