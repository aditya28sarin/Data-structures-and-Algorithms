// ou are given an integer array nums sorted in ascending order, and an integer target.

// Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7]
// might become [4,5,6,7,0,1,2]).

// If target is found in the array return its index, otherwise, return -1.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -10^4 <= nums[i] <= 10^4
// All values of nums are unique.
// nums is guranteed to be rotated at some pivot.
// -10^4 <= target <= 10^4


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

//searching is done using binary search
int searchRotatedSortedArray(vector<int>& nums, int target) {
        
		int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(target == nums[mid]) {
                return mid;
            } 
            
            
            if(nums[l] <= nums[mid]) {
                if(target > nums[mid] || target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if(target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }

int main()
{
    int size_of_array;
    cin>>size_of_array;

    vector<int> input_array(0,size_of_array)
    for(int i=0;i<size_of_array;i++)
    {
        int temp;
		cin>>temp;
		input_array.push_back(temp);
    }

    int element;
    cin>>element;

    cout<<searchRotatedSortedArray(input_array,element);
}