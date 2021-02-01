// URL: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include<bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int n){

    int m[n][n]; 
  
    int i, j, k, L, q; 

    // one matrix. 
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L <= n-1; L++)  
    { 
        for (i = 1; i <= n - L; i++)  
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++)  
            { 
                q = m[i][k] + m[k + 1][j] 
                    + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 

}


int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n); 
} 