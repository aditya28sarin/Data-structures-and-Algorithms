#include<iostream>

using namespace std;

class car
{
public:
    int car_id;
    char colour[4];
    float engine_no;
    double distance;

    void distance_travelled();
    float petrol_used();
    char music_player();
    void display(int a, int b)
    {

        cout<< "car id is=\t" <<a<< "\ndistance travelled =\t" <<b + 5;
    }
};


int main()

{
    car c1;

    c1.car_id=15158;
    c1.distance=230;
    c1.display(15158,230);
}








// Eg 2

#include<iostream>

using namespace std;



class Testing
{
public:
    string nickname;
    int id;

    void printname();

    void printid()

    {
        cout<<"Your ID Is: "<<id;
    }

};

void Testing::printname()
{

    cout<<"Your Name Is: "<<nickname;
}


int main()
{

    Testing t1;
    t1.nickname="Aditya Sarin";
    t1.id=1;

    t1.printname();
    cout<<endl;

    t1.printid();
    cout<<endl;

}

