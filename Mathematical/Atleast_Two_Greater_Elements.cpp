#include<iostream>
using namespace std;

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

        for(int i=0;i<n;i++)
        {

            for(int j=i;j<n;j++)
            {
                if(arr[j]<=arr[i])
                {

                    int temp;
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }

            for(int i=0;i<n;i++)
            {

                if(i==n-1 || i==n-2)
                {
                    continue;
                }
                else
                {
                cout<<arr[i]<<" ";
                }

            }
            cout<<endl;

    }
}
