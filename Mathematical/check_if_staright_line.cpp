// URL: https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()<=1) return true;
        if((c[1][0]-c[0][0])==0)
        {
            for(int i=0;i<c.size();i++)
            {
                if(c[i][0]!=c[0][0]) return false;
            }
            return true;
        }
        else
        {
            float m = (float)(c[1][1]-c[0][1])/(float)(c[1][0]-c[0][0]);
            for(int i=1;i<c.size();i++)
            {
                float h = (float)(c[i][1]-c[i-1][1])/(float)(c[i][0]-c[i-1][0]);
                if(h!=m) return false;
            }
        }
        return true;
    }
};