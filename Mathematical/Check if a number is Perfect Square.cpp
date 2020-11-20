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

        double sq_n=sqrt(n);

        int sq_n_abs =abs(sq_n);
        if(sq_n_abs==sq_n)
        {
            cout<<1<<endl;
        }
        else
        {

            cout<<0<<endl;
        }


    }

}
