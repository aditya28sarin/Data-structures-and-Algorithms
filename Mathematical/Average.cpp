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


        int arr[size1],sum[size1]={0},avg[size1]={0};

        for(int i=1;i<=size1;i++)
        {   sum[0]=0;
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
            avg[i]=(int)(sum[i]/i);
            cout<<avg[i]<<" ";
        }
            cout<<endl;


    }
}
