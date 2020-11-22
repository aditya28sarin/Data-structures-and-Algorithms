#include<iostream>

using namespace std;

class baseClass
{

public:
    void func()
    {

        cout<<"Base class show fucntion called"<<endl;
    }

    virtual void print()
    {

        cout<<"Base class print fucntion called"<<endl;

    }
};

class myderived : public baseClass
{
    void func()
    {

        cout<<"Derived class show fucntion called"<<endl;
    }

    void print()
    {

        cout<<"Derived class print fucntion called"<<endl;

    }

};

int main()
{

    baseClass *bctr;
    myderived obj1;

    bctr=&obj1;

    bctr -> print();
    bctr -> func();
}
