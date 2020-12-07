// Problem: Given an array arr[] of n elements, write a function to search a given element x in arr[].

// Examples :  

// Input : arr[] = {10, 20, 80, 30, 60, 50, 
                     // 110, 100, 130, 170}
          // x = 110;
// Output : 6
// Element x is present at index 6

// Input : arr[] = {10, 20, 80, 30, 60, 50, 
                     // 110, 100, 130, 170}
           // x = 175;
// Output : -1
// Element x is not present in arr[].

#include <iostream> 
using namespace std; 
  
int linearSearch(int input_array[], int size_of_array, int x) 
{ 
    int i; 
    for (i=0; i<size_of_array; i++) 
    { 
    if (input_array[i] == x) 
        return i; 
    } 
    return -1; 
} 

int main() 
{ 
    int input_array[] = {1, 10, 30, 15}; 
    int x;
    cin>>x;
    int size_of_array = sizeof(input_array)/sizeof(input_array[0]); 
    std::cout << x << " is present at index " 
              << linearSearch(input_array, size_of_array, x); 
   
    return 0; 
} 