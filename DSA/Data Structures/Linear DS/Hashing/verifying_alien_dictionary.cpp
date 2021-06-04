class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size()-1;i++){
            
            string word1 = words[i];
            string word2 = words[i+1];
            
            int j1=0,j2=0;
            while(word1[j1]==word2[j2]){
                j1++;
                j2++;
            }
            
             int lval = order.find(word1[j1]);
             int rval = order.find(word2[j2]);
            
            if(lval>rval){
                return false;
            }
            
        }
        return true;
    }
};