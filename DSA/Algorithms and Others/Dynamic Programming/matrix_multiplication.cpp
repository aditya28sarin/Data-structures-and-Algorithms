
#include<bits/stdc++.h>
using namespace std;

int MCM(int arr[], int i, int j){
    
    if(i>=j){
        return 0;
    }

    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);

        if(temp < mn){
            mn=temp;
        }
    }

    return mn;
}



int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MCM(arr, 1,n-1); 
} 