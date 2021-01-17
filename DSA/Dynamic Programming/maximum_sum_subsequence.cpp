// URL: https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

#include<bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n){
    int i,j,max=0;
    int msis[n];

    for(int i=0;i<n;i++){
        msis[i]=arr[i];
    }

    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[i]>arr[j] && (msis[i]<arr[i]+msis[j])){
                msis[i]=arr[i]+msis[j];
            }
        }
    }


    for(i=0;i<n;i++){
        if(max<msis[i]){
            max=msis[i];
        }
    }

    return max;
}

int main()  
{  
    int arr[] = {1, 101, 2, 3, 100, 4, 5};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout << "Sum of maximum sum increasing "
            "subsequence is " << maxSumIS( arr, n ) << endl;  
    return 0;  
}  