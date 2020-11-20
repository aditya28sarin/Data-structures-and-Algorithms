#include<iostream>
#include<list>

using namespace std;

int main()
{

    list <int> ls1 {1,22,3,7,0};

    list <string> ls2 {"India","Dubai","Australia","Europe"};

    ls1.push_back(6);
    ls1.push_front(0);

    list <int> :: iterator p=ls1.begin(); //iterator

    while(p!=ls1.end())
    {
        cout<<*p;
        p++;
    }

    cout<<endl;
    cout<<"Total values:"<<ls1.size()<<endl;

    ls2.pop_back();
    ls2.pop_front();

    list <string> :: iterator p1=ls2.begin(); //iterator


    while(p1!=ls2.end())
    {
        cout<<*p1;
        p1++;
    }
cout<<endl;

    ls1.sort();
    list <int> :: iterator p2=ls1.begin();
    while(p2!=ls1.end())
    {
        cout<<*p2;
        p2++;
    }

 ls1.remove(22);
cout<<endl<<endl;
    list <int> :: iterator p3=ls1.begin();

 while(p3!=ls1.end())
    {
        cout<<*p3 ;
        p3++;
    }



}
