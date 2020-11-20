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

        int val=n/3;
        int rem=n%3;

        if(rem==0)
        {

            cout<<val<<endl;
        }
        else{
                cout<<0<<endl;


                }
    }
}
