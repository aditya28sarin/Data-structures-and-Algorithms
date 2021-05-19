// URL: https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int dp[1001];
    int MCSUtil(int i, vector<int>& cost){
        if(i>=cost.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        return dp[i] = min(MCSUtil(i+1,cost), MCSUtil(i+2,cost)) + cost[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(MCSUtil(0,cost), MCSUtil(1,cost));
    }
};