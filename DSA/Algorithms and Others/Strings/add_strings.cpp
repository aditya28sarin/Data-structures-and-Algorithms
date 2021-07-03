class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<char> st1,st2;
        string ans="";
        int carry=0;
        for(int i=0;i<num1.length();i++){
            st1.push(num1[i]);
        }
        
        
        for(int i=0;i<num2.length();i++){
            st2.push(num2[i]);
        }
        while(!st1.empty() || !st2.empty()){
            int sum=0;
            
            if(!st1.empty()){
                sum=sum+(st1.top()-'0');
                st1.pop();
            }else{
                sum=sum+0;
            }
            
            
            if(!st2.empty()){
                sum=sum+(st2.top()-'0');
                st2.pop();
            }else{
                sum=sum+0;
            }
            
            sum=sum+carry;
            carry=sum/10;
            ans=ans+to_string(sum%10);
            
        }
        
        if(carry>0){
            ans=ans+"1";
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};