#include<iostream>

using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {
        int size1;

        cin>>size1;

        int arr[size1];

        for(int i=0;i<size1;i++)
        {

            cin>>arr[i];

        }

        int value,count1=0;

        cin>>value;

        for(int i=0;i<size1;i++)
        {

            if(arr[i]<=value)
            {

                count1++;
            }

        }


        cout<<count1<<endl;

    }
}
