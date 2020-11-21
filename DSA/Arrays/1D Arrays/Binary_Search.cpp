
#include <bits/stdc++.h> 
using namespace std; 

// Recursive Binary Search
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 

    return -1; 
} 

int iterativeBinarySearch(int arr[], int l, int r, int x)
{
    while(l<r)
    {
       int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            r=mid-1;
  
        if (arr[mid] < x)
            l=mid+1; 
   
    }
}
  
int main(void) 
{ 
    int arr[] = { 2, 4, 6, 18, 38 }; 
    int x = 18; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? cout << "Element "<<x<<" is not present in array"
                   : cout << "Element "<<x<<"  is present at index " << result; 


    result = iterativeBinarySearch(arr,0,n-1,x);
    cout<<"\n\n--Iterative Binary Search--\n\n";
    (result == -1) ? cout << "Element is "<<x<<"  not present in array"
                   : cout << "Element is "<<x<<"  present at index " << result; 

    return 0; 
} 