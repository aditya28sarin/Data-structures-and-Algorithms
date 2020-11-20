#include<iostream>
#include<cmath>
using namespace std;

void isPrime(int n)
{
 if(n==1)
        {

            cout<<"No";
        }
        else if(n==2 || n==3)
        {
            cout<<"Yes";
        }

    for(int i=2;i<=sqrt(n);i++)
    {


        if(n%i==0)
        {
            cout<<"No";

            break;
        }

        else
        {
            if(i==floor(sqrt(n)))
            {
                cout<<"Yes";
            }

        }
        //Write your logic here
        /*n is prime only if it is not divisible by any i. We will not reach till n and 1 is already discarded*/
    }
   cout<<endl;
}


int main()
{

    int cases;
    cin>>cases;

    while(cases--)
    {

        int n;
        cin>>n;
        isPrime(n);
    }

    return 0;
}
