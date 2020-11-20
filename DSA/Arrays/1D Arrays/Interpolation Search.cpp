#include<iostream>
using namespace std;

int interpolation_search(int arr[], int key, int low, int high)
{
    while(low<=high)
    {
        int pos= low + ((key-arr[low])*(high-low)/(arr[high]-arr[low]));

        if(arr[pos]==key)
        {
            return pos;
        }

        if(arr[pos]>key)
        {
            high=pos-1;
            //return interpolation_search(arr,key,low,pos-1);

        }
        if(arr[pos]<key)
        {
            low=pos+1;
            //return interpolation_search(arr,key,pos+1,high);
        }
    }
    return -1;
}


int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n,key;
        cin>>n>>key;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        int val = interpolation_search(arr,key,0,n-1);
        cout<<val<<endl;


    }
}
