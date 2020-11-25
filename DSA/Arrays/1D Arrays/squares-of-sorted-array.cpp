// Given an array of integers A sorted in non-decreasing order, return an array of the squares 
//of each number, also in sorted non-decreasing order.

 

// Example 1:

// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Example 2:

// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 
 -------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size=A.size();
        vector<int> vt(size);
        int start=0,end=size-1;
       int i=0;
        
        while(start<=end)
        {
            if(abs(A[start])<=abs(A[end]))
            {
                vt[size-i-1]=A[end]*A[end];
                end--;
            }
            else
            {
                vt[size-i-1]=A[start]*A[start];
                start++;
            }
            i++;
        }
        return vt;
    }
};