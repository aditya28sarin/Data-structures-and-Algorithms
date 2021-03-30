// URL: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    
    void numIslandsUtil(vector<vector<char>>& grid, int x, int y){
        
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]!='1'){
            return;
        }
        
        grid[x][y]='2';
        
        numIslandsUtil(grid,x-1,y);
        numIslandsUtil(grid,x,y-1);
        numIslandsUtil(grid,x+1,y);
        numIslandsUtil(grid,x,y+1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int no_of_islands=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                if(grid[i][j]=='1')
                {
                    numIslandsUtil(grid,i,j);
                    no_of_islands++;   
                }
            }
        }
        return no_of_islands;
    }
};