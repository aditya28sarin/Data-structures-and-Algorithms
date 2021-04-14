// URL: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int res=0;
        int l_max=0;
        int r_max=0;
        
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=l_max){
                    l_max=height[l];
                }else{
                  res+=l_max-height[l];  
                }
                l++;
            }else{
                 if(height[r]>=r_max){
                    r_max=height[r];
                }else{
                  res+=r_max-height[r];  
                }
                r--;
            }
        }
        return res;
    }



    //Other approach 
    int trap(vector<int>& height){
        int n = height.size();
        vector<int> mxl(n);
        vector<int> mxr(n);

        mxl[0]=height[0];

        for(int i=1;i<n;i++){
            mxl[i]=max(mxl[i-1],height[i]);
        }

        mxr[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--){
            mxr[i]=max(mxr[i+1],height[i]);
        }

        vector<int> water(n);

        for(int i=0;i<n;i++){
            water[i]=min(mxl[i],mxr[i])-height[i];
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=water[i];
        }

        return sum;
    }
};