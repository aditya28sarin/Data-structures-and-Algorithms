#include<iostream>
#include<vector>

using namespace std;


int main()
{

    vector <int> v1(5,10);

    cout<<"Capacity is: "<<v1.capacity()<<endl;

    cout<<"Size is: "<<v1.size()<<endl;
    for(int i=0;i<5;i++)
    {

        cout<<v1[i]<<" ";
    }


    v1.push_back(15);

    cout<<endl;
    cout<<"Capacity is: "<<v1.capacity()<<endl;

    cout<<"Size is: "<<v1.size()<<endl;

    v1.pop_back();

    cout<<"Capacity is: "<<v1.capacity()<<endl;

    cout<<"Size is: "<<v1.size()<<endl;

        cout<<endl;
    cout<<v1.at(2)<<endl;

    vector <int> :: iterator it=v1.begin();

    v1.insert(it,35);

    for(int i=0;i<5;i++)
    {

        cout<<v1[i]<<" ";
    }




}
