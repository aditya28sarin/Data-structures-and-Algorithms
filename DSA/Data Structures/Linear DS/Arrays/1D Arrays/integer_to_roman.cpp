// URL: https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
         vector<int> s_i = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> s_str = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        vector<string> str;
        
        for(int i=0;i<s_i.size();i++){
            
            while(num>=s_i[i]){
                str.push_back(s_str[i]);
                num=num-s_i[i];    
            }
        
        }
            
            
         string ans ="";
        for(auto x : str)
            ans+=x;
        return ans;
        
    }
};