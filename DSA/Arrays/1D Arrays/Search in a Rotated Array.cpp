#include<iostream>
using namespace std;

int main()

{
    int cases;

    cin>>cases;

    while(cases--)
    {

        int n,val;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int no;
        cin>>no;

        for(int i=0;i<n;i++)
        {

            if(arr[i]==no)
            {
                val=i;
                break;
            }
            else
            {

                val=-1;
            }
        }
            cout<<val<<endl;
    }
}
