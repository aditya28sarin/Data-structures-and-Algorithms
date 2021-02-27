// URL: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
       vector<pair<int,int>> vt;
        int n = points.size();
        for(int i=0;i<points.size();i++){
            vt.push_back(make_pair(points[i][0],points[i][1]));
        }
        
        sort(vt.begin(),vt.end());
        
        int max = INT_MIN;
        for(int i=0;i<n-1;i++){
            
            if(max<(vt[i+1].first-vt[i].first)){
                max=vt[i+1].first - vt[i].first;
            }
        }
        
        return max;
    }
};