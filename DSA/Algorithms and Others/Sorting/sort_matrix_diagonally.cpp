// URL: https://leetcode.com/problems/sort-the-matrix-diagonally/


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
     int r = mat.size();
     int c = mat[0].size();

    unordered_map<int,vector<int>> m1;
      vector<vector<int>> map;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                m1[i-j].push_back(mat[i][j]);
            }
        }

        unordered_map<int,vector<int>> :: iterator it;
        
        for(it=m1.begin(); it!=m1.end();it++){
            sort(it->second.begin(),it->second.end(),greater<int>());
        }
        
          for(int i=0;i<r;i++)
          {
            for(int j=0;j<c;j++)
            {
                mat[i][j]=m1[i-j].back();
                m1[i-j].pop_back();
            }
         }
        
        return mat;
    }
};