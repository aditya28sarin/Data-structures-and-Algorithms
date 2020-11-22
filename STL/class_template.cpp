#include<iostream>
using namespace std;


template <typename T, typename U>
class Aditya
{

private:
    T kg;
    U grams;

public:
    void setData(T x, U y)
    {

        kg=x;
        grams=y;
    }

    T getkgData()
    {

        return kg;

    }

    U getgramData()
    {

        return grams;
    }

};

int main()
{

    Aditya <int, float>obj1;
    obj1.setData(5,7);

    cout<<"Value is: "<<obj1.getkgData()<<endl;

     Aditya <float, float>obj2;

     obj2.setData(5.5,88);
    cout<<"Value is: "<<obj2.getkgData()<<endl;

    cout<<"Value is: "<<obj1.getgramData()<<endl;


    cout<<"Value is: "<<obj2.getgramData()<<endl;




}
