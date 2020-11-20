#include<iostream>
#include<cmath>

using namespace std;

int main()
{

    int cases;
    cin>>cases;


    while(cases--)
    {
        double n,ans;

        cin>>n;

        ans=cbrt(n);

        cout<<floor(ans)<<endl;
    }



}
