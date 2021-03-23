// URL: https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    
  static bool myfunc(pair<int, int>& a, pair<int, int>& b){
        if(a.second == b.second)
            return a.first > b.first;
        return
            a.second < b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> counts;
        unordered_map<int, int> ht;
        
        for(int num : nums)
            ht[num]++;
        
        for(auto val : ht)
            counts.push_back({val.first, val.second});
        
        sort(counts.begin(), counts.end(), myfunc);
        
        vector<int> result;
        for(int i=0; i<counts.size(); i++){
            while(counts[i].second>0){
                result.push_back(counts[i].first);
                counts[i].second--;
            }
        }
        
        return result;
    }
   
};