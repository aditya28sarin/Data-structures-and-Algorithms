// URl: https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans=ans+4;
                    i++;
                }else if(s[i+1]=='X'){
                    ans=ans+9;
                    i++;
                }else{
                    ans=ans+1;
                }
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans=ans+40;
                    i++;
                }else if(s[i+1]=='C'){
                    ans=ans+90;
                    i++;
                }else{
                    ans=ans+10;
                }
            }
            
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ans=ans+400;
                    i++;
                }else if(s[i+1]=='M'){
                    ans=ans+900;
                    i++;
                }else{
                    ans=ans+100;
                }
            }
            else if(s[i]=='V'){
                ans=ans+5;
            }else if(s[i]=='L'){
                ans=ans+50;
            }else if(s[i]=='D'){
                ans=ans+500;
            }else if(s[i]=='M'){
                ans=ans+1000;
            }
        }
        
        return ans;
    }
};