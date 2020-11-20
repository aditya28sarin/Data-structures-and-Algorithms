#include<iostream>

using namespace std;

int main()
{

    int cases,size1;

    cin>>cases;

    while(cases--)
    {

        cin>>size1;

        int arr[size1];

        for(int i=0;i<size1;i++)
        {
            cin>>arr[i];
        }

        int val_max=arr[0];
        int val_min=arr[size1-1];

        for(int i=0;i<size1;i++)
        {
            if(arr[i]>=val_max)
            {

                val_max=arr[i];
            }
            if(arr[i]<=val_min)
            {

                val_min=arr[i];
            }

        }

        cout<<val_max<<" "<<val_min<<endl;
    }
}
