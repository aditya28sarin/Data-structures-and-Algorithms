#include<iostream>

using namespace std;

class Complex
{
private:
    int real,imag;
public:

    Complex()
    {

        real=0;
        imag=0;
    }
    Complex(int x, int y)
    {

        real=x;
        imag=y;
    }

    Complex operator + (Complex c)
    {
        Complex temp;
        temp.real=real+c.real;
        temp.imag=imag+c.imag;
        return temp;

    }
    void print()
    {

        cout<<real<<"+"<<"i"<<imag<<endl;
    }

};

int main()
{

    Complex c1(2,4);
    c1.print();
    Complex c2(1,5);
    c2.print();

    Complex c3;
    c3=c1+c2; //c2.add(c1);
    c3.print();

    Complex c4;

    c4=c1+c2+c3;
    c4.print();


}


