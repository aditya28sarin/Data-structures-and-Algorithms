#include<iostream>
using namespace std;

class A
{

public:
    int x;
    static int count;

    A()
    {

        count++;
    }

    static int getCount()
    {

        return count;
    }

};

int A::count=0;

int main()
{

    cout<<"Initial Count is:"<<A::count<<endl;// 0

    A a1,a2;

cout<<"Count is:"<<A::count<<endl;//2

cout<<"Count is:"<<A::getCount()<<endl;//same thing as above but using static member function



}
