#include<iostream>
#include<cmath>
using namespace std;


void conv_bin(int n);
int main()
{

    int cases,n;

    int j=0;

    cin>>cases;

    while(j<cases)
    {
        cin>>n;
        conv_bin(n);
        cout<<endl;
    }

}


void conv_bin(int n)
{
int len_1=3,len_2=4,len;
    if(n>0 && n<8)
    {
        len=len_1;
    }
    else if(n>=8 && n<16)
    {

        len=len_2;
    }

    int a[10],val;
    for (int i=1;i<=len;i++)
    {
        if(n/2!=0)
        {
    a[i]=n%2;
    val=n/2;
    n=val;
        }
        else if(n/2==0)
        {
            a[i]=1;
            break;
        }

    }
int new_val[4]={0,0,0,0};
    for (int i=1;i<=len;i++)
    {
        for (int j=len;j>=i;j--)
        {

                new_val[i]=new_val[i]^a[j];
        }
    }

    for (int i=len;i>=1;i--)
    {
  cout<<new_val[i];
    }

    cout<<endl;

int sum=0;
    for (int u=1;u<=len;u++)
    {
        sum=sum+new_val[u];

    }

cout<<sum;
}

