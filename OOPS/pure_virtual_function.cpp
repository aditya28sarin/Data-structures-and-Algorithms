#include<iostream>

using namespace std;


class shape
{

public:
    virtual void getArea()=0;  //pure virtual function

};

class circle:public shape{
public:
    void getArea()
    {

        int r;
        cin>>r;

         cout<<3.14*r*r<<endl;
    }

};

int main()

{
    circle c1;
    c1.getArea();
}

