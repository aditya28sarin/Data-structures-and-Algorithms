#include<iostream>

using namespace std;

class Base
{
public:
    void print()
    {

        cout<<"Hello from base class"<<endl;
    }
};

class child : public Base

{
    public:
    void print()
    {

        cout<<"Hello from child class"<<endl;
    }

};

class nochild : public Base

{
    public:
    void print()
    {

        cout<<"Hello from nochild class"<<endl;
    }

};


int main()
{

    Base b;
    b.print();
    child c;
    c.print();
    nochild nc;
    nc.print();


}
