#include<iostream>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int arr_size;
        cin>>arr_size;
        int arr[arr_size],arr1[arr_size];
        for(int i=0;i<arr_size;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<arr_size;i++)
        {
            arr1[i]=-1;
        }
        for(int i=0;i<arr_size;i++)
        {
            if(arr[i]!=-1)
            {
                arr1[arr[i]]=arr[i];
            }
        }

        for(int i=0;i<arr_size;i++)
        {
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
    }
}

