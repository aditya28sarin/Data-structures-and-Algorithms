#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {

        int n;
        cin>>n;

        int arr[n],arr1[n];

        for (int i=0;i<n;i++)
        {

            cin>>arr[i];
        }
        int temp=arr[n-1];
        for(int i=1;i<n;i++)
        {
            arr1[i]=arr[i-1];
        }
            arr1[0]=temp;
        for(int i=0;i<n;i++)
        {

            cout<<arr1[i]<<" ";
        }
        cout<<endl;
    }
}   



