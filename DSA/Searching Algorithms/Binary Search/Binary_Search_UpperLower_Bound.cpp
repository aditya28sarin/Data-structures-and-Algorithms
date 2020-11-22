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


void binarySearch(int l, int r, int arr[], int element, int &lower, int &upper)
{

    if(r>=l)
    {

        int m = l + (r-l)/2;

        if(arr[m]==element)
        {
            lower=arr[m];
            binarySearch(m+1,r,arr,element, lower, upper);
        }

        if(arr[m]>element)
        {
            if(arr[m-1]==element)
            {
                upper=arr[m];
            }
            else
            {
                lower=arr[m];
                upper=arr[m];
            }
            
            binarySearch(l,m-1,arr,element, lower, upper);
        }
        
        if(arr[m]<element)
        {
            binarySearch(m+1,r,arr,element, lower, upper);
        }
    }

}

int main()
{
    int size;
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int element;
    cin>>element;

    int lower,upper;
    lower=-1;
    upper=-1;
    binarySearch(0,size-1,arr, element, lower, upper);

    cout<<"Lower bound of "<<element<<" is:"<<lower<<endl;
    cout<<"Upper bound of "<<element<<" is:"<<upper<<endl;


}


//method 2
#include<bits/stdc++.h>
using namespace std;


int lowerBound(int l, int r, int arr[], int element)
{

    if(l>r)
    {
        return l;
    }

    int m = l + (r-l)/2;

    if(arr[m]>=element)
    {   
       return lowerBound(l,m-1,arr,element);
    }
   
    return lowerBound(m+1,r,arr,element);

}



int upperBound(int l, int r, int arr[], int element)
{

    if(l>r)
    {
        return l;
    }
        int m = l + (r-l)/2;
   
        if(arr[m]<=element)
        {   
           return upperBound(m+1,r,arr,element);
        }
        
       return upperBound(l,m-1,arr,element);
 
}

int main()
{
    int size;
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int element;
    cin>>element;

    cout<<"Lower bound of "<<element<<" is:"<<lowerBound(0,size-1,arr, element)<<endl;
    cout<<"Upper bound of "<<element<<" is:"<<upperBound(0,size-1,arr, element)<<endl;


}