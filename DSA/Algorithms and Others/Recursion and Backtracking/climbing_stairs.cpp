// URL: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    long long int t[46];
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2)
            return n;
        
        if(t[n]!=0) return t[n];
        
        return t[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};