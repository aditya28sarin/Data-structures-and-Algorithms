class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        vector<vector<int>> ans;
        int n=points.size();
        
        for(int i=0;i<n;i++){
            
            maxHeap.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), {points[i][0],points[i][1]}});
            
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        
        while(maxHeap.size()>0){
            ans.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
            maxHeap.pop();
        }
        
        return ans;
    }
};