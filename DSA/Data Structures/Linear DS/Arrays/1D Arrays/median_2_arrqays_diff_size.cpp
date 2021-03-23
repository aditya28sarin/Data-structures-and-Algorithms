// URL: https://leetcode.com/problems/median-of-two-sorted-arrays/


class Solution {
public:
 
    int getMax(vector<int> arr, int num)
    {
        if(num == 0)
            return INT_MIN;
        return arr[num - 1];
    }
    
    int getMin(vector<int> arr, int num)
    {
        if(num == arr.size())
            return INT_MAX;
        return arr[num];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int lo = 0;
        int hi = nums1.size();
        int total = nums1.size() + nums2.size();

        while(lo <= hi)
        {
            int part1 = (lo + hi) / 2;
            int part2 = ((total + 1) / 2) - part1;

            int left1 = getMax(nums1, part1);
            int right1 = getMin(nums1, part1);

            int left2 = getMax(nums2, part2);
            int right2 = getMin(nums2, part2);

            if(left1 <= right2 && left2 <= right1)
            {
                if(total % 2 == 0)
                {
                    return (double)(max(left1, left2) + min(right1, right2)) / 2;
                }
               return max(left1, left2); 
            }
           if(left1 > right2)
               hi = part1 - 1;
            else 
                lo = part1 + 1;
        }

       return -1; 
    }
    
};