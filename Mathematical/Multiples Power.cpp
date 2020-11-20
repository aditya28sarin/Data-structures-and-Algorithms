#include<iostream>

using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {

        int max_limit;

        cin>>max_limit;

        long long int mul_3=0,mul_7=0,sum=0;

        while(mul_3<max_limit)
        {

            mul_3=3+mul_3;

                if(mul_3<max_limit)
                {
                        sum=sum+mul_3;

                }



        }


        while(mul_7<max_limit)
        {

            mul_7=7 +mul_7;

            if(mul_7<max_limit)
            {

                if(mul_7%7==0 && mul_7%3==0)
                {

                    continue;
                }


                else
                {
            sum=sum+mul_7;
                }


            }


        }
        cout<<sum<<endl;


    }
}
