class Solution {
public:
    int t[2001][2001];
    bool isPalindrome(string &s, int i, int j){
        
        if(i>=j) return true;
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int palindromePartition(string s, int i, int j){
        if(i>=j){
            return 0;
        }    
        
        if(isPalindrome(s,i,j)==true){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        
        int min_ans=INT_MAX;
        int left,right, temp;
        for(int k=i;k<=j-1;k++){
            
            if(t[i][k]!=-1){
                left=t[i][k];
            }else{
                left = palindromePartition(s,i,k);
            }
            
            if(t[k+1][j]!=-1){
                right=t[k+1][j];
            }else{
                right = palindromePartition(s,k+1,j);
            }
            
            temp = left + right + 1;
            
            if(temp<min_ans){
                min_ans=temp;
            }
        }
        return t[i][j] = min_ans;
    }
    
    
    int minCut(string s) {
        int i=0;
        int j=s.length()-1;
        memset(t,-1,sizeof(t));
        return palindromePartition(s,i,j);
    }
};