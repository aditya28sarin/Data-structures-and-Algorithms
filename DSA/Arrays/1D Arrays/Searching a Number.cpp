#include<iostream>
using namespace std;

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {

        int n,k;
        cin>>n>>k;
        int val;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];

         }
         for(int i=0;i<n;i++)
        {
           if(arr[i]==k)
            {
               val=i+1;
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
