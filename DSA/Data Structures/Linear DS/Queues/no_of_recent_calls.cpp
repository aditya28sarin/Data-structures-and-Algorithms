// URL: https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
public:
    int counter;
   queue <int> q;
    
    RecentCounter() {
        counter=0;
    }
    
    int ping(int t) {
        
        q.push(t);
        
        while(q.front()<t-3000)
            q.pop();
        return q.size();
    }
};