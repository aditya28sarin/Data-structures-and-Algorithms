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
        int k=n;
        int x, sum=0;
        while(n>0)
        {
            x=n%10;
            n=n/10;
            sum=sum+x;
        }
        k=sum;
        int j=0;
        while(sum>0)
        {
        int l=sum%10;
        sum=sum/10;
        j++;

        }
       // cout<<j<<endl;
        int i=j-1,sum1=0;
        int br=k;
        while(i>=0)
        {
            x=k%10;
            k=k/10;
            sum1=sum1+pow(10,i)*x;
            i--;
        }

        if(br==sum1)
        {

            cout<<"YES"<<endl;
        }
        else
        {

            cout<<"NO"<<endl;
        }

//        cout<<br<<endl;
//        cout<<sum1<<endl;

    }
}
