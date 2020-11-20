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
        int sum=0;
        int x,temp;
        temp=n;
    while(temp>0)
    {


        x=temp%10;
        temp=temp/10;
            int prod=1;
        for(int i=x;i>0;i--)
        {

            prod=prod*i;
        }

        sum=sum+prod;

    }

    if(sum==n)
    {

        cout<<"Perfect"<<endl;
    }
    else{
        cout<<"Not Perfect"<<endl;
    }

    }

}
