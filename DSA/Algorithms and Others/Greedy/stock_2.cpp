// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int p=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                p+=prices[i]-prices[i-1];
            }
        }
        
        return p;
    }
};