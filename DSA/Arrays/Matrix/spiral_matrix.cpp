// Given an m x n matrix, return all elements of the matrix in spiral order.

//  left,top--->******<---right
//             ******   <------Let this be a dummy matrix for explanation
//             ******
//  bottom---> ******


//  in order to got spirally this the very easy traversal we are going to employ:

//  move left till right and increment top
                 
//             ******<---right,left
//    top--->  ******   
//             ******
//  bottom---> ******

//  Now from top to bottom we are going to travers downward and decrement right.

//                ******<---left
//                ******   
//                ******
// top,bottom---> ******
//                    ^
//                    |
//                  right

// We move right till left note that left is static we are move left,right etc pointers.


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
       int n=matrix.size();
        int m=matrix[0].size();
        int size= n*m;
        int left=0,right=m-1,top=0,bottom=n-1;
        vector<int> vt;
        while(vt.size()<size)
        {
            for(int i=left; i<=right && vt.size()<size;i++)
            {
                vt.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i=top; i<=bottom && vt.size()<size; i++)
            {
                vt.push_back(matrix[i][right]);
            }
            right--;
            
            for(int i=right; i>=left && vt.size()<size;i--)
            {
                vt.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            for(int i=bottom; i>=top && vt.size()<size;i--)
            {
                vt.push_back(matrix[i][left]);
            }
            left++;
        }
        return vt;
    }
};