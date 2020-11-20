#include<iostream>

using namespace std;

int main()
{
    int cases;

    cin>>cases;

    while(cases--)
    {

        string str;
        int count1=0;

        cin>>str;


    for(int i=0;i<str.length();i++)
    {
        if(isalpha(str[i]))
        {

           count1++;
        }

    }

    cout<<count1<<endl;


    }
}
