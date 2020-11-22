// Given an integer x, find it’s square root. If x is not a perfect square, then return floor(√x).

// Examples :

// Input: x = 4
// Output: 2
// Explanation:  The square root of 4 is 2.

// Input: x = 11
// Output: 3
// Explanation:  The square root of 11 lies in between
// 3 and 4 so floor of the square root is 3

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h> 
using namespace std; 
  
// Returns floor of square root of x 
int floorSqrt(int find_sqroot_of) 
{ 
    // Base cases 
    if (find_sqroot_of == 0 || find_sqroot_of == 1) 
    return x; 
  
    // Staring from 1, try all numbers until 
    // i*i is greater than or equal to x. 
    int i = 1, result = 1; 
    while (result <= find_sqroot_of) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
} 
  
  
int main() 
{ 
	int find_sqroot_of;
	cin>>find_sqroot_of;	
	cout << floorSqrt(x) << endl; 
	return 0; 
} 