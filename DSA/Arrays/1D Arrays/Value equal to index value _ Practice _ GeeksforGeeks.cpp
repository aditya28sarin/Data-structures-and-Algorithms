
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

        int arr[size1],val[size1];

        for(int i=1;i<=size1;i++)
        {
            cin>>arr[i];
        }
        int j=1;
        for(int i=1;i<=size1;i++)
        {
            if(arr[i]==i)
            {
                val[j]=arr[i];
                j++;
            }
        }

        if(j==1)
        {

            cout<<"Not Found"<<endl;
        }
        else{
        for(int i=1;i<j;i++)
        {

            cout<<val[i]<<" ";
        }
         cout<<endl;
        }


    }
    }
