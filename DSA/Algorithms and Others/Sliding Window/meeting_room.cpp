class Solution {
public:
    
    
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]))
            return true;
        else
            return false;
    } 
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1)
            return true;
        
        sort(intervals.begin(),intervals.end(), comp);
        
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>intervals[i+1][0]){
                return false;
            }
        }
        return true;
    }
};