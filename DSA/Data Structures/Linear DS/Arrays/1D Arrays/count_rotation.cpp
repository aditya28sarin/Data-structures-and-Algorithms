// Given an ascending sorted rotated array Arr of distinct integers of size N. 
// The array is right rotated K times. Find the value of K.

// Input:
// N = 5
// Arr[] = {5, 1, 2, 3, 4}
// Output: 1
// Explanation: The given array is 5 1 2 3 4. 
// The original sorted array is 1 2 3 4 5. 
// We can see that the array was rotated 
// 1 times to the right.


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int cp=0,temp=arr[0];
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<temp)
	            temp=arr[i];
	    }
	    
	    for(int i=0;i<n-1;i++)
	    {
	        if(arr[i]==temp)
	        break;
	        if(arr[i]>=temp)
	            cp++;
	    }
	    return cp;
	}

};