// URL: geeksforgeeks.org/matrix-chain-multiplication-dp-8/


#include<bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int arr[], int l, int r){
    if(l>=r){
        return 0;
    }

    int res = INT_MAX;
    int temp;

    for(int i=l;i<r;i++){

        temp = MatrixChainOrder(arr,l,i) + MatrixChainOrder(arr,i+1,r) + arr[l-1]*arr[i]*arr[r];

        res = min(temp,res);
    }

    return res;
}


int main() 
{
    int arr[] = { 1, 2, 3, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1); 
} 