// URL:https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = points.size();
        vector<pair<int,pair<int,int>>> v;
        
        //Find all euclidean distances
        int dist;
        for(auto it: points)
        {
            dist = it[0]*it[0] + it[1]*it[1];
            v.push_back({dist,{it[0],it[1]}});
        }
        sort(v.begin(),v.end());
        
        vector<vector<int>> ans(K);
        for(int i=0;i<K;++i)
        {
            ans[i].push_back(v[i].second.first);
            ans[i].push_back(v[i].second.second);
        }
        return ans;
    }
};