#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int cases;

cin>>cases;



while(cases--)
{

    long long int n;
        cin>>n;
        long long int k=1,c=0;
        long long int z;
        z=n;
        while(k>0)
        {
        k=z/10;
        z=k;
        c++;
        }





long long int i=c-1,sum=0,x;
    while(n>0)
    {

        x=n%10;
        n=n/10;
        sum=sum+ pow(10,i)*x;
        i--;

    }

    cout<<sum<<endl;
}


}
