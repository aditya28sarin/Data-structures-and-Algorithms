// URL: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int>& arr) {
    
    sort(arr.begin(), arr.end(),  greater<int>());

    int a = 0,b=a+1,c=arr.size()-1;
    int sum=0;
    while(b<c){
        sum+=arr[b];
        a=b+1;
        b=a+1;
        c--;
    }
    return sum;
    }
};