

//memoization + optimization 
class Solution {
public:
    
    int static t[101][10001];
    int eggDropUtil(int e, int f){
       if(f==0 || f==1 || e==1)
           return f;
        
        if(t[e][f]!=-1)
            return t[e][f];
        
        int mn = INT_MAX;
        int low,high;
        for(int k=1;k<=f;k++){
            
            if(t[e-1][k-1]!=-1){
                low=t[e-1][k-1];
            }else{
                low=eggDropUtil(e-1,k-1);
                t[e-1][k-1]=low;
            }
            
            
            if(t[e][f-k]!=-1){
                high=t[e][f-k];
            }else{
                high=eggDropUtil(e,f-k);
                t[e][f-k]=high;
            }
            
            
            int temp = 1+max(low,high);
                
            mn=min(mn,temp);
        }
        
        return t[e][f]=mn;
    }
    
    
   
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return eggDropUtil(k,n);
    }
};


//memoization + optimization + Binary Search 
class Solution {
public:
    int helper(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
        
            int left = helper(k-1, mid-1, memo);
            int right = helper(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     
    
            mn = min(mn, temp); 
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return helper(k, n, memo);
    }
};