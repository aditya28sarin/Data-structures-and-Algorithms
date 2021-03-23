//URL: https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    
    int firstBadVersion(int n) {
       int l =1,r=n;
        
        while(l<=r){
            int m =(r-l)/2 + l;
            
            if(!isBadVersion(m-1) && isBadVersion(m)) return m;
                
            else if(!isBadVersion(m)) l=m+1;
            
            else r=m-1;
        }
        
        return l;
    }
};
