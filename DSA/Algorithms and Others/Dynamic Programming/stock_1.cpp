// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mn=INT_MAX;
        int p=0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mn){
                mn=prices[i];
            }
            
            if(prices[i]-mn>p){
                p=prices[i]-mn;
            }
        }
        
        return p;
    }
};