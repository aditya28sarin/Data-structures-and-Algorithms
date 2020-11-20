#include<iostream>
using namespace std;

void sortingArray(int arr[],int n)
{
    int temp =arr[0];
    for(int i=0;i<n-1;i++)
    {

        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n;
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sortingArray(arr,n);
        cout<<arr[n-1]*arr[n-2]<<endl;
    }
}
