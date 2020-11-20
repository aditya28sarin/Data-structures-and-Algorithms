#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int cases;

cin>>cases;

while(cases--)
{
    int n1,n2;

    cin>>n1>>n2;


    n1=n1+n2;
    n2=n1-n2;
    n1=n2-n1;
    cout<<abs(n1)<<" "<<abs(n2)<<endl;



}
}
