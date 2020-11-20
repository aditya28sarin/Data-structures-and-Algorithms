#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int l,b,h;
        cin>>l>>b>>h;

        cout<<2*((l*b)+(b*h)+(h*l))<<" "<<l*b*h<<endl;
    }
}