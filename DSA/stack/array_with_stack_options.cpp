//URL: https://leetcode.com/problems/build-an-array-with-stack-operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        
        int st=1;
        int i=0;
        while(i<target.size()){
            
            if(target[i]==st){
                ans.push_back("Push");
                i++;
                st++;
            }
            else if(st<target[i]){
                while(st!=target[i]){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    st++;
                }
                
            }
            
        }
        
        return ans;
    }
};
