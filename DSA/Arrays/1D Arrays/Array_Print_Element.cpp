#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{

    int test_cases,n,myval;
    int i=0;
    int *arr=(int *)malloc(n*sizeof(int *));

        cin>>test_cases;

    while(i<test_cases)
    {

        cin>>n>>myval;

        for(int j=0;j<n;j++)
        {

            cin>>arr[j];

            if(j==myval)
            {
                cout<<arr[j]<<endl;
            }
        }
        i++;
    }
}
