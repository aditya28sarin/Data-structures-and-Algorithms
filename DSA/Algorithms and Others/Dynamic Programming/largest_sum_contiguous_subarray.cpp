#include<bits/stdc++.h>
using namespace std;


int maxSubArraySum(int arr[], int n){
    int meh=0;
    int msf=INT_MIN;
    for(int i=0;i<n;i++){
        meh = meh + arr[i];

        if(meh < arr[i]){
            meh = arr[i];
        }
        if(msf < meh){
            msf = meh;
        }
    }
    return msf;
}

int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 