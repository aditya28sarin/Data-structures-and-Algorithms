#include<bits/stdc++.h>
using namespace std;

int printLargestPrimeFactor(int num)
{
    while(num%2==0)
    {
        //cout<<"2"<<" ";
        num=num/2;
    }
    int temp=3;
    for(int i=3;i<=sqrt(num);i=i+2)
    {
        
        while(num%i==0)
        {
           // cout<<i<<" ";
            num=num/i;

            if(i>temp)
                temp=i;
        }    
    }

    if(num>2)
        return num;
        //cout<<num;

    return temp;
}




int main()
{   int cases;
    cin>>cases;
    while(cases--)
    {
    long long int num;
    cin>>num;

    cout<<printLargestPrimeFactor(num)<<endl;

    }

} 