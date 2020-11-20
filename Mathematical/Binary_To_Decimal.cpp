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
        long long int k=n;
        long long int x;
        int i=0;
        while(n>0)
        {
            x=n%10;
            n=n/10;
            i++;
        }
        int sum=0,j=0,l;
        while(k>0)

        {
            l=k%10;
            k=k/10;
            sum=sum+ pow(2,j)*l;
            j++;
        }
            cout<<i<<endl;
            cout<<sum<<endl;
    }

}
