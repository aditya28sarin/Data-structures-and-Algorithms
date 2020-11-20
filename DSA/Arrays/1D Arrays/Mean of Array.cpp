#include<iostream>
#include<cmath>
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

    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
    }

    double sum=0,avg;


    for(int i=0;i<n;i++)
    {

        sum=sum+arr[i];

    }
        avg=floor(sum/n);
        cout<<avg;
}
}
