// URL: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/


//O(rlogc)
class Solution {
public:
    int countNegatives(vector<vector<int>>& arr) {
        int count = 0;
    for(int i=0;i<arr.size();i++){
        int l = 0, r = arr[i].size()-1;
        int i_l = i, i_r = r;
        while(l<=r){
            int m = (r-l)/2 + l;
            
            if(arr[i][0]<0){
                count+=arr[i].size();
                break;
            }
            
            else if (arr[i][r]>=0){
                break;
            }
            
            else if (arr[i][m]<0 && arr[i][m-1]<0)
                r=m-1;
                
            else if (arr[i][m]<0 && arr[i][m-1]>=0){
                count+=i_r-m+1;
                break;
            }
            
            
            else if (arr[i][m]>=0 && arr[i][m+1]>=0)
                l=m+1;
                
            else if(arr[i][m]>=0 && arr[i][m+1]<0){
                count+=i_r-m;
                break;
            }
                
        }
        
    }
    
    return count;
    }
};


//O(r+c)

// The idea is to start from the top right corner.
// If it is negative then all the numbers below in that column will be negative. We can add all of it to our answer nr-r. 
//Then we move one coulmn left c--and repeat the same process.
// If it is not negative then we move one row down r++ until we find a negative number.