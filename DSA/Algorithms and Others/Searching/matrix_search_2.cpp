// URL: https://leetcode.com/problems/search-a-2d-matrix-ii/


class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int r=0;
        int c=matrix[0].size()-1;
        
        while(r<matrix.size() && c>=0){
            if(target==matrix[r][c]){
                return true;
            }else if(target<matrix[r][c]){
                c--;
            }else{
                r++;
            }
        }
        
        return false;
    }
};