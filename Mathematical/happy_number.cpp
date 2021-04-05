// URL: https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> st;
        int sum=0;
        while(n!=1){ 
            
            if(st.find(n)!=st.end()){return false;}
            st.insert(n);
            int sum=0;
            while(n){
                int x = n % 10;
                n=n/10;
                sum=sum+x*x;
            }     
            n=sum;
        }
        return true;
    }
};