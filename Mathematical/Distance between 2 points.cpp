#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int cases;

cin>>cases;



    while(cases--)
    {

        int x1,x2,y1,y2;

        cin>>x1>>y1>>x2>>y2;

        double ans =sqrt((pow(y1-y2,2)+pow(x1-x2,2)));

        cout<<ceil(ans)<<endl;
    }
}

