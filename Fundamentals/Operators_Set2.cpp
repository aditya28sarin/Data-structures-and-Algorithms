#include<iostream>

using namespace std;

int main()
{
    int cases;
    int n1,n2;

    int i=0;

    cin>>cases;
    while(i<cases)
    {

    cin>>n1>>n2;


    if(n1<n2)
    {

        cout<<n1<<" is less than "<<n2<<endl;
    }
    else if(n1>n2)
    {

        cout<<n1<<" is greater than "<<n2<<endl;
    }

    else
    {

        cout<<n1<<" is equals "<<n2<<endl;
    }

    i++;

    }




}
