#include<iostream>

using namespace std;

int main()
{

    int cases;
    cin>>cases;
    while(cases--)
    {
        double value1,value2;
        int ans;
        cin>>value1>>value2;

         ans=value1/value2;
        double ans_1=value1-(ans*value2);
        cout<<ans_1<<endl;




    }
}
