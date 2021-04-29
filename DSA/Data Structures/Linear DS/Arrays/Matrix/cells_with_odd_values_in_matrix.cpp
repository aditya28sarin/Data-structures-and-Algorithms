// URL: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
   int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n,vector<int>(m,0));int row;int column;int cnt=0;
        for(int i=0;i<indices.size();i++)
        {
            row=indices[i][0];
            column=indices[i][1];
            for(int j=0;j<matrix[0].size();j++)
            {
                matrix[row][j]++;
                
            }
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][column]++;
                
            }}
            for(int k=0;k<matrix.size();k++)
            {
                for(int m=0;m<matrix[k].size();m++)
                {
                    if(matrix[k][m]%2!=0)
                       cnt++; 
                }
            }
      return cnt;  
    }
};