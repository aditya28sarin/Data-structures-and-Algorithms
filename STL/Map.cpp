#include<iostream>
#include<map>

using namespace std;

int main()
{       //1st type of initiialization
        map <int, string> customer;

        customer[100]="Aditya";
        customer[123]="Bruh";
        customer[181]="Abhinav";
        customer[200]="Ansh";

      //2nd type of initiialization
        map <int,string> c{{100,"Aditya"}, {123,"Bruh"},{181,"Abhinav"}, {200,"Ansh"}};

        map <int,string> :: iterator it1=c.begin();

        while(it1!=c.end())
        {

            cout<<it1->second<<endl;
            it1++;
        }
        cout<<endl;
        cout<<c.at(100)<<endl;

        cout<<c.size()<<endl;
        cout<<c.empty();



          map <int,string> :: iterator it2=c.begin();

        while(it2!=c.end())
        {

            cout<<it2->second<<endl;
            it2++;
        }

         c.insert(pair<int,string>(205,"Saurabh"));

            map <int,string> :: iterator it3=c.begin();
        cout<<endl<<endl;
        while(it3!=c.end())
        {

            cout<<it3->second<<endl;
            it3++;
        }

}
