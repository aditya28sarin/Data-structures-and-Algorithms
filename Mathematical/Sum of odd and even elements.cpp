#include<iostream>
using namespace std;

int main()
{
    int cases;

    cin>>cases;

    while(cases--)

    {
        int limit;

        cin>>limit;

       long long int arr[limit];

        long long int sum_even=0,sum_odd=0;

        for(long long int i=1;i<=limit;i++)
        {
            if(i%2!=0)
            {
                sum_odd=sum_odd + i;


            }
            else{
                sum_even=sum_even+i;
            }
        }
        cout<<sum_odd<<" "<<sum_even<<endl;

    }


}
