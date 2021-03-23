#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.




-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------



//returns the maximum product of a subarray using sliding window algorithm
int maxProduct(vector<int>& input_array) {
    int current_product=1,resulting_product=1;
    int maximum_product=0;

    if(input_array.size()==0)
        return 0;
   
   if(input_array.size()==1)
        return input_array[0];

    for(int i=0;i<input_array.size();i++)
    {
        //exception to handle array element 0
        if(input_array[i]==0)
        {
            if(input_array[i]>=maximum_product)
            {
                maximum_product=input_array[i];
            }
            continue;
        }
        
        if(input_array[i]!=0)
            current_product=current_product*input_array[i];
      
        
        if(i>=1  && input_array[i]!=0)
        {
            if(input_array[i-1]!=0)
                current_product = current_product/input_array[i-1];
            if(input_array[i-1]==0)
                current_product=current_product/input_array[i-2];
        }
        
        if(i>=0 && input_array[i]!=0)
        {
            if(input_array[i-1]==0)
            {
                resulting_product=1;
            }
            resulting_product=resulting_product*current_product;
        
            if(resulting_product>=maximum_product)
            {
                maximum_product=resulting_product;
            }
        }
    }
    return maximum_product;
}
    
    
    int main()
    {
        int array_size;
        
        cin>>array_size;
        
        vector<int> input_array;
        
        for(int i=0;i<array_size;i++)
        {
            int temp_var;
            cin>>temp_var;
            input_array.push_back(temp_var);
        }
        
        cout<<maxProduct(input_array);
    }