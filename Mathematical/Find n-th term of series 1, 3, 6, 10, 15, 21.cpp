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
        arr[1]=1;
        for(int i=2;i<=n;i++)
        {

            arr[i]=arr[i-1]+i;
        }


        cout<<arr[n]<<endl;


    }
}
