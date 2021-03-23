// Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

// A subarray is a contiguous subsequence of the array.

// Return the sum of all odd-length subarrays of arr.

 

// Example 1:

// Input: arr = [1,4,2,5,3]
// Output: 58
// Explanation: The odd-length subarrays of arr and their sums are:
// [1] = 1
// [4] = 4
// [2] = 2
// [5] = 5
// [3] = 3
// [1,4,2] = 7
// [4,2,5] = 11
// [2,5,3] = 10
// [1,4,2,5,3] = 15
// If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
// Example 2:

// Input: arr = [1,2]
// Output: 3
// Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
// Example 3:

// Input: arr = [10,11,12]
// Output: 66
 

// Constraints:

// 1 <= arr.length <= 100
// 1 <= arr[i] <= 1000


// -------------------------------------------------------------------------------------------------------
// 						CODE
// -------------------------------------------------------------------------------------------------------


//method 1 O(n^3)
#include<bits/stdc++.h>
using namespace std;

//return sum of all odd size subarrays separated out from the input array 
int sumOddLengthSubarrays(vector<int> &input_array, int size_of_array)
{   

    int j=1;
    int sum=0;
    while(j<=size_of_array)
    {
       int i=0;
       while(i<size_of_array)
       {
           if(j%2!=0)
           {
               if(i+j<=size_of_array)
               {
                   for(int k=0;k<i+j;k++)
                   {
                       sum=sum+input_array[k];
                   }
               }

           }
       }
    }
    return sum;
}

int main()
{
    int size_of_array;

    cin>>size_of_array;

    vector<int> input_array;

    int temp_var;

    for(int i=0;i<size_of_array;i++)
    {
        cin>>temp_var;
        input_array.push_back(temp_var);
    }

    cout<<sumOddLengthSubarrays(input_array, size_of_array);
}


//method 2 O(n^2) - Sliding Window 

// class Solution {
// public:
//     int sumOddLengthSubarrays(vector<int>& input_array) {
   
//         int size_of_array=input_array.size();
//         int res=0;
//         for(int len=1;len<=size_of_array;len+=2)
//         {
//             for(int i=0,sum=0;i<size_of_array;i++)
//             {
//                 sum+=input_array[i];
                
//                 if(i>=len)
//                 {
//                     sum-=input_array[i-len];
//                 }
                
//                 if(i>=len-1)
//                 {
//                     res+=sum;
//                 }
//             }
//         }
//             return res;
//         }
// };