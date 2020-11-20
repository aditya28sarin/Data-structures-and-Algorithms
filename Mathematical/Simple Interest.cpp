#include<iostream>
#include<cmath>

using namespace std;

int main()

{
    int cases;

    cin>>cases;

    while(cases--)
    {
        int p,r,t;

        cin>>p;
        cin>>r;
        cin>>t;

        cout<<floor(0.01*p*r*t)<<endl;

    }
}
