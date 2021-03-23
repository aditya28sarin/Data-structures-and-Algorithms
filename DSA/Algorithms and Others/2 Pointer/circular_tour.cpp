// URL: https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int st_idx=-1;
        int sum=0,overall_sum=0;
        
        for(int i=0;i<gas.size();i++){
            
            gas[i]-=cost[i];
            
            sum+=gas[i];
            
            if(sum>=0){
                if(st_idx==-1){
                    st_idx=i;
                }
            }else{
                sum=0;
                st_idx=-1;
            }
            
            overall_sum+=gas[i];
        }
        
        if(overall_sum<0){
            return -1;
        }
        
        return st_idx;
    }
};