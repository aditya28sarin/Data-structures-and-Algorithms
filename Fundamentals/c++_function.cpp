#include<iostream>

using namespace std;


int calcSum(int a, int b, int c);

int main()
{

    int n,j,sum_final[20];
    int a,b,c;
    j=0;


    cin>>n;

    while(j<n)
    {

        cin>>a>>b>>c;
        sum_final[j]=calcSum(a,b,c);
        j++;


    }

    for(int i=0; i<n;i++)

    {

        cout<<sum_final[i]<<endl;
    }
}



int calcSum(int a, int b, int c)
{

    int sum=0;

    sum= a+b+c;

    return sum;

}
