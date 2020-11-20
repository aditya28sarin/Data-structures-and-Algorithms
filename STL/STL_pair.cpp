#include<iostream>
using namespace std;


class student
{
public:
    string name;
    int age;

    void setStudent(string s, int a)
    {
        name=s;
        age=a;
    }

    void showStudent()
    {

        cout<<"\nName: "<<name<<"\nAge: "<<age<<endl;
    }

};

int main()
{
    pair <string,int> p1;
    p1=make_pair("Aditya",10);
    cout<<p1.first<<" ";
    cout<<p1.second<<endl;

    pair <string,string> p2;
    p2=make_pair("India","Mumbai");
     cout<<p2.first<<" ";
    cout<<p2.second<<endl;

    pair <string, float> p3;
    p3=make_pair("Sarin",35.5f);
    cout<<p3.first<<" ";
    cout<<p3.second<<endl;

    pair <int, student> p4;
    student s1;
    s1.setStudent("Anandilal",55);
    p4=make_pair(28,s1);
    cout<<p4.first<<" ";
    student s2=p4.second;//we need to store this in some other variable of student type
    s2.showStudent();


}
