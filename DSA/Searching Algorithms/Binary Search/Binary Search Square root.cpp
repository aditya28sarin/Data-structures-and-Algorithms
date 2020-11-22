#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

long long binary_search_sqrt(int arr[], int l, int r, int k)
{
    while(l<=r)
    {
    int m=l+(r-l)/2;
    if(arr[m]==k)
        return arr[m];
    if(arr[m]>k)
        r=m-1;
    if(arr[m]<k)
         l=m+1;
    }
    return -1;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int key;
        cin>>key;
        int arr[10];
        int i=1;
        while(i*i<=key)
        {
            arr[i]=i;
            i++;
        }
        int number=arr[i-1];
        cout<<binary_search_sqrt(arr,1,i-1,number)<<endl;
    }
}
