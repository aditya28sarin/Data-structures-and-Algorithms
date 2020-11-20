#include<iostream>

using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while (cases--)
    {
        int n,sum=0;

        cin>>n;

        while(n!=0)
        {
            int x;

            x=n%10;
            sum=sum+x;
            n=n/10;
        }
        cout<<sum<<endl;


    }

}
