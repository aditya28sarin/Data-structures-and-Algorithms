// URL:https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{
    int max=a[0];
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    
    int arr[max+1]={0};
    
    for(int i=0;i<size;i++)
    {
        arr[a[i]]+=1;
    }
    for(int i=0;i<=max;i++)
    {
        if(arr[i]>size/2)
            return i;
    }
    
    return -1;
    
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
