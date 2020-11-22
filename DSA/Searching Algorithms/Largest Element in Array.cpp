#include<iostream>
using namespace std;

int main()
{


    int cases,size1,val;
    cin>>cases;

    while(cases--)
    {

        cin>>size1;

        int arr[size1];

        for(int i=0;i<size1;i++)
        {

            cin>>arr[i];

        }

            val=arr[0];
        for(int i=0;i<size1;i++)
        {

            if(arr[i]>=val)
            {
                val=arr[i];
            }
        }

    cout<<val<<endl;

    }

}
