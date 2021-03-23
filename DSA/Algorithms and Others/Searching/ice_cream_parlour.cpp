// Sunny and Johnny like to pool their money and go to the ice cream parlor. Johnny never buys the same flavor that Sunny does.
// The only other rule they have is that they spend all of their money.

// Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.

// Function Description

// Complete the icecreamParlor function in the editor below. It should return an array containing the indices of the prices of the two flavors they buy, sorted ascending.

// icecreamParlor has the following parameter(s):

// m: an integer denoting the amount of money they have to spend
// cost: an integer array denoting the cost of each flavor of ice cream



-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


vector<int> icecreamParlor(int m, vector<int> arr) {
    
    vector<int> vt;
    bool flag=false;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(i!=j)
            {
                if(arr[i]+arr[j]==m)
                {
                    vt.push_back(i+1); 
                    vt.push_back(j+1);
                    flag=true;
                    break;
                }
            }
        }
        if(flag==true)
            break;
    }
    return vt;
}



//O(n) solution using hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;
        vector<int> vt;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(target-nums[i])==0)
            {
                mp[nums[i]]=i;
            }
            else
            {
                vt.push_back(mp[target-nums[i]]);
                vt.push_back(i);
                break;
            }
        }
        return vt;
    }
};