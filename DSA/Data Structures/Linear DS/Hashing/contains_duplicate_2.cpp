class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                mp.insert({nums[i],i});   
            }
            else{
                auto itr = mp.find(nums[i]);
                 if(itr!=mp.end()){
                    if(abs(itr->second - i)<=k){
                        return true;
                    }else{
                        mp.erase(itr->first);
                        mp.insert({nums[i],i});
                    }
                }    
            }
            
        }
        
        return false;
    }
};

