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

        int arr[size1],count1=0;

        for(int i=0;i<=size1-1;i++)
        {
            cin>>arr[i];
        }


        for(int i=0;i<=size1-2;i++)
        {
            if(arr[i+1]>=arr[i])
            {
                count1++;
            }
        }

        if(count1==size1-1)
        {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}



