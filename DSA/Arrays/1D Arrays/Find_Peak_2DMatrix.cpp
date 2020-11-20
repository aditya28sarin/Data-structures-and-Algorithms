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