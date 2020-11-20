#include<iostream>

using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {

        int size1,x;

        cin>>size1>>x;
        int arr[size1],c1=0,c2=0;

        for(int i=0;i<size1;i++)
        {
            cin>>arr[i];
        }

        for(int i=0;i<size1;i++)
        {
           if(arr[i]>=x)
           {

               c1++;
           }

           if(arr[i]<=x)
           {

               c2++;
           }
        }

        cout<<c2<<" "<<c1<<endl;

    }
}
