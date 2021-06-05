class Solution {
public:
    int countPrimes(int n) {
        bool vt[n+1];
        memset(vt,true,sizeof(vt));
        
        if(n == 0) return 0;
        if(n == 1) return 0;
        
        vt[0]=false;
        vt[1]=false;
        for(int i=2;i<n;i++){
            if(vt[i]==true){
                for(int j=2;i*j<=n;j++){
                    vt[i*j]=false;
                }
            }
        }
        
        int no=0;
        for(int i=2;i<n;i++){
            if(vt[i]==true){
                no++;
            }
        }
        
        return no;
    }
};