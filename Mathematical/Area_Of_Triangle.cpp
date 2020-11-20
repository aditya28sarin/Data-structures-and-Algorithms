#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int cases;

cin>>cases;



    while(cases--)
    {

        double r_length,r_width;
        double base,height;
        double radius;

        cin>>r_length>>r_width>>base>>height>>radius;

        double r_area=r_length*r_width;
        double tri_area=0.5*base*height;
      int c_area=floor(3.14*radius*radius);

        cout<<floor(r_area)<<" "<<floor(tri_area)<<" "<<c_area<<endl;
    }

}



