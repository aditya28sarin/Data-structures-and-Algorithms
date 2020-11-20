#include<iostream>
#include<math.h>
using namespace std;

int main()
{

    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,sum=0,i=0,x;
        cin>>n;
        while(n>0)
        {
            x=n%2;
            n=n/2;
            sum=sum+pow(10,i)*x;
            i++;

        }
             cout<<sum<<endl;

    }
}
