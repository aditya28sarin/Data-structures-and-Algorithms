#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

    int cases;

    cin>>cases;

    cin.ignore();

    while(cases--)
    {

    string str;


    getline(cin,str);

    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
        {
            cout<<str[i];
        }
    }

cout<<endl;

    }

}
