#include<iostream>
using namespace std;

template <typename T, typename U>
U add(T x, U y)
{

    return (x+y);
}

int main()
{

        cout<<"Addition of 2 integers:"<<add<int, float>(3,4.5)<<endl;

        cout<<"Addition of 2 float:"<<add<float,float>(3.5f,4.7f)<<endl;

    return 0;

}
