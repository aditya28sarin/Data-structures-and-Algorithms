#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)
        return a;
    if(b==0)
        return b;
    if(a==b)
        return a;
    
    if(a>b)
        return gcd(a-b,b);

    return gcd(a,b-a);
}



int lcm(int a, int b)
{
    if(a==0)
        return a;
    if(b==0)
        return b;
    if(a==b)
        return a;
    
    if(a>b)
        return gcd(a-b,b);

    return gcd(a,b-a);
}




int main()
{   int cases;
    cin>>cases;
    while(cases--)
    {
    long long int num1,num2;
    cin>>num1>>num2;

    int res=gcd(num1,num2);

    //cout<<"GCD of "<<num1<<" & "<<num2<<" is: "<<res<<endl;

     long long int res2=lcm(num1,num2);

    long long  int res_final=(num1/res2)*(num2/res2)*res2;

    //cout<<"LCM of "<<num1<<" & "<<num2<<" is: "<<res_final;

    cout<<res_final<<" "<<res<<endl;
    }

} 