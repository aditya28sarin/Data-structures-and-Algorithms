#include<iostream>
using namespace std;


int findCnt(int arr[], int x, int n)
{
    if(x==0)
        return 1;
    
    if(n==0)
        return 0;
    
    if(arr[n-1]>x)
        return findCnt(arr,x,n-1);
    
    else
    {
        return findCnt(arr,x,n-1)+findCnt(arr,x-arr[n-1], n-1);
    }
    
}


int main() 
{ 
    int arr[] = { 1,2,1 }; 
    int n = sizeof(arr) / sizeof(int); 
    int x = 3; 
  
    cout << findCnt(arr, x, n); 
  
    return 0; 
} 