#include<iostream>

using namespace std;

class Geeks
{
public:
    int id;

    Geeks()

    {
        cout<<"Default Constructor Called"<<endl;
        id=-1;
    }

    Geeks(int x)
    {

        cout<<"Paramaterized COnstructor Called"<<endl;
        id=x;
    }


};

int main()
{

    Geeks g1;
    cout<<"Geek ID Is:"<<g1.id<<endl;

    Geeks g2(21);
    cout<<"Geek ID Is:"<<g2.id<<endl;

}
