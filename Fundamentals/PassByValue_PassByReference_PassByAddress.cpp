#include<iostream>

using namespace std;


void passByValue(int x, int y)
{

    int temp;

    temp=x;
    x=y;
    y=temp;

}

void passByReference( int &x, int &y)
{

    int temp;

    temp=x;
    x=y;
    y=temp;


}

void passByAddress( int *x, int *y)
{
    int temp;

    temp=*x;
    *x=*y;
    *y=temp;

}

int main()
{
    int a=5,b=6;

    cout<<a<<" "<<b<<endl;

    passByValue(a,b);

    cout<<a<<" "<<b<<endl;

    passByReference(a,b);


    cout<<a<<" "<<b<<endl;

    passByAddress(&a,&b);
    cout<<a<<" "<<b<<endl;


}
