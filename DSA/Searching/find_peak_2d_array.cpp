// An element is a peak element if it is greater than or equal to its four neighbors, left, right,
//top and bottom. For example neighbors for A[i][j] are A[i-1][j], A[i+1][j], A[i][j-1] and 
//A[i][j+1]. For corner elements, missing neighbors are considered of negative infinite value.

// Examples:

// Input : 10 20 15
        // 21 30 14
        // 7  16 32 
// Output : 30
// 30 is a peak element because all its 
// neighbors are smaller or equal to it. 
// 32 can also be picked as a peak.

// Input : 10 7
        // 11 17
// Output : 17


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100; 


void findMax(int arr[][MAX], int rows, int cols, int mid,int &max,int &max_index)
{
    
    max = arr[0][mid];
  
    for(int i=0;i<rows;i++)
    {
        if(arr[i][mid]>=max)
        {
            max=arr[i][mid];
            max_index=i;
        }
    }

}

int findPeakRec(int arr[][MAX], int rows, int cols, int mid)
{
    int max=0;
    int max_index=0;
    findMax(arr,rows,cols,mid,max,max_index);

    if(max>=arr[max_index][mid-1] && max>=arr[max_index][mid+1])
        return max;

    else if (max<arr[max_index][mid-1])
        return findPeakRec(arr,rows,cols, mid-ceil(double(mid/2)));

    return findPeakRec(arr, rows, cols, mid + ceil((double)mid / 2));    
}


int findPeak(int arr[][MAX], int rows, int columns) 
{ 
    return findPeakRec(arr, rows, columns, columns / 2); 
} 

int main() 
{ 
    int arr[][MAX] = { { 10, 8, 10, 10 }, 
                       { 14, 13, 12, 11 }, 
                       { 15, 9, 11, 21 }, 
                       { 16, 17, 19, 20 } }; 
  
    int rows = 4, columns = 4; 
    cout << findPeak(arr, rows, columns); 
    return 0; 
} 