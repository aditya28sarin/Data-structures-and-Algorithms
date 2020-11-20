#include<iostream>

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
            sum=sum+(x*x*x);
        }


        if(k==sum)
        {

            cout<<"Yes"<<endl;
        }
        else
        {

            cout<<"No"<<endl;
        }
    }

}
