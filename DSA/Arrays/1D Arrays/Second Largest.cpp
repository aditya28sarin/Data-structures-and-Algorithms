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

        int largest=arr[0];
        for(int i=0;i<size1;i++)
        {
            if(arr[i]>=largest)
            {
                largest=arr[i];
            }

        }


        int second_largest=0;
        for(int i=0;i<size1;i++)
        {

            if(arr[i]!=largest)
            {
                if(arr[i]>=second_largest)
                {
                    second_largest=arr[i];
                }
            }


        }
        cout<<second_largest<<endl;

    }

}


