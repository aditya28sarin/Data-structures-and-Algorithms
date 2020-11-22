#include<iostream>

using namespace std;

class A
{
public:
    int a;


};

class B : public A
{

public:
    int b;



};


class C : public A
{

public:
    int c;


};

class D : public B, public C
{

public:
    int d;


};


int main()
{
    D obj;
    //obj.A=10;
    //obj.B=100;

    obj.B::a=10;
    obj.C::a=100;

    obj.b=20;
    obj.c=20;
    obj.d=20;

    cout<< "\n A from ClassB  : "<< obj.ClassB::a;
              cout<< "\n A from ClassC  : "<< obj.ClassC::a;

              cout<< "\n B : "<< obj.b;
              cout<< "\n C : "<< obj.c;
              cout<< "\n D : "<< obj.d;





}
