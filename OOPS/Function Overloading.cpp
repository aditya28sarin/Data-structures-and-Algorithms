#include<iostream>

using namespace std;

class aditya
{
public:

    void func(int x)
    {

         cout << "value of x is " << x << endl;
    }

    void func(double x)
    {

         cout << "value of x is " << x << endl;
    }

    void func(int x, int y)
    {
             cout << "value of x and y is " << x << ", " << y << endl;


    }


};


int main()
{


    aditya a;

    a.func(5);
    a.func(53.5);
    a.func(2,1);

}
