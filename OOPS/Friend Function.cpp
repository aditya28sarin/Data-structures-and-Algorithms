#include<iostream>

using namespace std;

class distance
{
private:
    int x;

public:
    distance()
    {

        x=0;
    }

    void display()

    {
        cout<<x<<endl;
    }

friend void addvalue(distance& d);

};


void addvalue(distance& d)
{

    d.x=d.x+5;

}


int main()
{
distance d1;

d1.display();

addvalue(d1);

d1.display();
return 0;
}
