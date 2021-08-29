class Solution {
public:
    
   
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n =intervals.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        pq.push(intervals[0][1]);
        
        for(int i = 1;i<n;i++){
            if(intervals[i][0]>=pq.top()){
                pq.pop();
            }
            
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
        
    }
};