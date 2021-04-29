// URL: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> vt;
        
        if(n%2!=0){
            vt.push_back(0);  
            n--;
        }
        
        int power=0;
        int no=1;
        while(n--){
             vt.push_back(pow(-1,power)*no);
             
            if(n%2==0){
                no++;
            }
             power++;
         }
        
        return vt;
    }
};