#include<iostream>

using namespace std;

int main()
{

    int n1,n2,cases,temp;
    int sum=0,diff=0,mul,div;

    cin>>cases;

    while(cases--)
    {

        cin>>n1>>n2;

        if(n1>n2)
        {
        cout<<n1+n2<<endl;
        cout<<n1-n2<<endl;

        cout<<n1/n2<<endl;
         cout<<n1*n2<<endl;
        }
        else{
            temp=n1;n1=n2;n2=temp;
            cout<<n1+n2<<endl;
        cout<<n1-n2<<endl;

        cout<<n1/n2<<endl;
        cout<<n1*n2<<endl;
        }

    }
}
