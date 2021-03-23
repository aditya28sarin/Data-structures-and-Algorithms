//URL:https://leetcode.com/problems/crawler-log-folder/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int count=0;
        for(int i=0;i<logs.size();i++){
            
            if(count<0){count=0;}
            
            if(logs[i]=="../"){
                count--;
                
            }
            else if (logs[i]=="./"){
                continue;
            }
            else{
                count++;
            }
            
        }
        
        if(count<0){return 0;}
        return count;
    }
};
