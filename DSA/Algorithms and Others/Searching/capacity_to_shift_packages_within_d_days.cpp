// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:

    bool isValid(vector<int>& weights, int n, int D, int mid){
        int days=1;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum=sum+weights[i];
            
            if(sum>mid){
                days++;
                sum=weights[i];
            }
            
            if(days>D){
                return false;
            }
        }
        return true;
    }
    
    
    int shipWithinDays(vector<int>& weights, int D) {
        
        int start=INT_MIN;
        int end=0;
        int res;
        for(int i=0;i<weights.size();i++){
            if(start<weights[i]){
                start=weights[i];
            }
            end=end+weights[i];
        }
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isValid(weights,weights.size(),D, mid)){
                res=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        
        return res;
    }
};