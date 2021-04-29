// URL: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1=INT_MIN;
        int m2=INT_MIN;
        
        for(auto element:nums){
            
            if(m1<element){
                m2=m1;
                m1=element;
            }
            
            else if(m2<element){
                m2=element;
            }
        }
        
        return (m1-1)*(m2-1);
    }
};