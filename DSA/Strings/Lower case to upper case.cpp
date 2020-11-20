#include<iostream>

using namespace std;

int main()
{

    int cases;
    cin>>cases;

    while(cases--)
    {
        string str;

        cin>>str;

        for(int i=0;i<str.length();i++)
        {

            str[i]=toupper(str[i]);

        }

        cout<<str<<endl;


    }


}
